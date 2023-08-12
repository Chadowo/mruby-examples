#include <stdio.h>

#include <mruby.h>
#include <mruby/compile.h>

/* Loading ruby code from a file */
int main(int argc, char *argv[]) {
    mrb_state* mrb = mrb_open();
    if(!mrb) {
        fprintf(stderr, "Couldn't initialize MRuby\n");
        return 1;
    }

    // Open our file
    FILE* ruby_file = fopen("main.rb", "r");
    if(!ruby_file) {
        fprintf(stderr,
                "Couldn't find a main.rb file in the current directory, quitting...\n");
        mrb_close(mrb);
        return 1;
    }

    // Pass it to MRuby
    mrb_load_file(mrb, ruby_file);

    fclose(ruby_file);
    mrb_close(mrb);
    return 0;
}
