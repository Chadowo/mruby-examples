#include <stdio.h>

#include <mruby.h>
#include <mruby/string.h>
#include <mruby/variable.h>
#include <mruby/value.h>

/* This sample program shows you how to push various tipes of
 * variables to ruby
 * TODO: Get the variables and print them */
int main(int argc, char* argv[]) {
    mrb_state* mrb = mrb_open();
    if(!mrb) {
        fprintf(stderr, "Couldn't initialize MRuby\n");
        return 1;
    }

    // Pushing variables to ruby is relatively easy, here we define a constant,
    // FOO, with the integer value 42
    mrb_define_const(mrb, mrb->kernel_module, "FOO", mrb_fixnum_value(42));

    // Globals
    mrb_gv_set(mrb,
               mrb_intern_lit(mrb, "$bar"),
               mrb_str_new_lit(mrb, "I'm a global!"));

    // TODO: Instance variables

    // Class variables
    struct RClass* foobarKlass = mrb_define_class(mrb, "Foobar", mrb->object_class);
    mrb_mod_cv_set(mrb,
                   foobarKlass,
                   mrb_intern_lit(mrb, "@@baz"),
                   mrb_float_value(mrb, 50.55));

    // Module variables (AKA class variables but on a module)
    struct RClass* foobazModule = mrb_define_module(mrb, "Foobaz");

    mrb_mod_cv_set(mrb,
                   foobazModule,
                   mrb_intern_lit(mrb, "@@quux"),
                   mrb_float_value(mrb, 15.0));

    // We can also get the variables we defined, for example; getting the
    // module variable @@quux
    mrb_value quuxCvar = mrb_cv_get(mrb,
                                     mrb_obj_value(foobazModule),
                                     mrb_intern_lit(mrb, "@@quux"));

    printf("@@quux: %f\n", mrb_float(quuxCvar));

    mrb_close(mrb);
    return 0;
}
