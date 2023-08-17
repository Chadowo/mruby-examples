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
    FILE* rubyFile = fopen("main.rb", "r");
    if(!rubyFile) {
        fprintf(stderr,
                "Couldn't find a main.rb file in the current directory, quitting...\n");
        mrb_close(mrb);
        return 0;
    }

    // Pass it to MRuby
    mrb_load_file(mrb, rubyFile);

    fclose(rubyFile);
    mrb_close(mrb);
    return 0;
}
