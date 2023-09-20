#include <stdio.h>

#include <mruby.h>
#include <mruby/compile.h>

/* Keyword arguments (also called keyword parameters) are a type of arguments
 * added back in CRuby 2.0 that let's us specify arguments like so:
 *
 * foo(keyword1: 'hi', keyword2: false)
 *
 * We can shuffle the order of args too:
 *
 * foo(keyword2: false, keyword:1 'hi')
 *
 * It doesn't really matter as long as the keyword's present.
 */

/* This method uses 2 required kwargs (both integers):
 *
 * method(foo:, bar:)
 */
static mrb_value mrb_kwargs_method(mrb_state* mrb, mrb_value self) {
    mrb_int kwNum = 2;
    mrb_int kwRequired = 2;

    mrb_sym kwNames[] = {
        mrb_intern_cstr(mrb, "foo"), mrb_intern_cstr(mrb, "bar")
    };

    mrb_value kwValues[kwNum];
    const mrb_kwargs kwArgs = { kwNum, kwRequired, kwNames, kwValues, NULL };

    mrb_get_args(mrb, ":", &kwArgs);

    printf("Keyword argument foo: %ld\nKeyword argument bar: %ld\n",
           mrb_fixnum(kwValues[0]),
           mrb_fixnum(kwValues[1]));

    return mrb_nil_value();
}

/* TODO: method with positional arguments and keyword arguments*/

int main(int argc, char *argv[]) {
    // Initiate mruby
    mrb_state* mrb = mrb_open();
    if(!mrb) {
        fprintf(stderr, "Couldn't initialize MRuby\n");
        return 1;
    }

    mrb_define_method(mrb, mrb->kernel_module, "method", mrb_kwargs_method, MRB_ARGS_REQ(2));

    mrb_load_string(mrb, "method(foo: 25, bar: 10)");

    mrb_close(mrb);
    return 0;
}
