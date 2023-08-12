#include <stdio.h>

#include <mruby.h>
#include <mruby/variable.h>
#include <mruby/string.h>

/* Equivalent to:
 *
 * class Human
 *    def initialize(name)
 *      @name = name
 *    end
 * end
 */
static mrb_value human_new(mrb_state *mrb, mrb_value self) {
    mrb_value name;
    mrb_get_args(mrb, "S", &name);

    // Set instance variable "@name" to mrb_value name
    mrb_iv_set(mrb, self, mrb_intern_lit(mrb, "@name"), name);

    return self;
}

/* This method returns a string greeting another human.
 * Equivalent to:
 *
 * class Human
 *   # ...
 *   def greet(human)
 *     "Hello there #{human.name}"
 *   end
 * end
 *
 * NOTE: since we're using the mruby api there's no need
 * for an attribute reader, so this is not exactly like the above
 * ruby code! 
 */
static mrb_value human_greet(mrb_state *mrb, mrb_value self) {
    mrb_value other_human;
    mrb_get_args(mrb, "o", &other_human);

    // Our greeting will look as follows:
    // Hello there #{other human name}
    //
    // so, we'll need the other human's instance name

    // Grab the other human's name
    mrb_value other_name = mrb_iv_get(mrb, other_human, mrb_intern_lit(mrb, "@name"));

    // We start building our greeting
    mrb_value greeting = mrb_str_append(mrb,
                                        mrb_str_new_cstr(mrb, "Hello there "),
                                        other_name);

    // Print the greeting
    mrb_p(mrb, greeting);

    return self;
}

int main(int argc, char* argv[]) {
    mrb_state* mrb = mrb_open();
    if(!mrb) {
        fprintf(stderr, "Couldn't initialize MRuby\n");
        return 1;
    }

    // We create our class, and define methods inside that same class.
    struct RClass* human_klass = mrb_define_class(mrb, "Human", mrb->object_class);
    mrb_define_method(mrb, human_klass, "initialize", human_new, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, human_klass, "greet", human_greet, MRB_ARGS_REQ(1));

    // Create some humans and make them greet each other!
    const char* code = "human1 = Human.new('John Doe')\n"
                       "human2 = Human.new('Jane Doe')\n"
                       "human1.greet(human2)\n"
                       "human2.greet(human1)\n";

    // FIXME: Warning: implicit function declaration?
    mrb_load_string(mrb, code);

    mrb_close(mrb);
    return 0;
}
