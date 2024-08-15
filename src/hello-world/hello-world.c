#include <stdio.h>

#include <mruby.h>
#include <mruby/compile.h>

/* Basic hello world with MRuby */
int main(int argc, char *argv[]) {
    // Initiate MRuby
    mrb_state* mrb = mrb_open();
    if(!mrb) {
        fprintf(stderr, "Couldn't initialize MRuby\n");
        return 1;
    }

    // Load Ruby program from string
    mrb_load_string(mrb, "puts 'Hello World!'");

    mrb_close(mrb);
    return 0;
}
