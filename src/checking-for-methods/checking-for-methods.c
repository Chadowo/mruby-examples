#include <stdio.h>

#include <mruby.h>
#include <mruby/value.h>

/* This function will perform a search in the Ruby side for the method that
   you that'd specify it to. A return value of 1 means that it was found, 0
   the opposite */
static int check_method(mrb_state* mrb, char* method_name) {
    // Create a symbol corresponding to the method name
    mrb_sym method_sym = mrb_intern_cstr(mrb, method_name);

    // Either 1 (true) or 0 (false)
    return mrb_obj_respond_to(mrb, mrb->object_class, method_sym);
}

mrb_value mrb_example_method(mrb_state* mrb, mrb_value self) {
    // Empty method...

    return mrb_nil_value();
}

int main(int argc, char* argv[]) {
    mrb_state* mrb = mrb_open();
    if(!mrb) {
        fprintf(stderr, "Couldn't initialize MRuby\n");
        return 1;
    }

    // We define a dummy method
    mrb_define_method(mrb,
                      mrb->kernel_module,
                      "example_method",
                      mrb_example_method,
                      MRB_ARGS_NONE());

    // Checking for a method
    if(check_method(mrb, "example_method")) {
      printf("'example_method' found!\n");
    }

    mrb_close(mrb);
    return 0;
}
