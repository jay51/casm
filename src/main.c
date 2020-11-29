#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "utils.h"
#include "lexer.h"



int main(int argc, char** argv) {

    int option;
    char* file_name = NULL;
    while((option = getopt(argc, argv, "l:a:S:s:")) != -1){
        switch(option){
        case 'l':
            file_name = optarg;
            lexer_init(file_name);
            TOKEN *tok;
            int count = 0;
            while(tok = lexer_get_next_token()) {
                if(tok->type == END_OF_FILE) break;
                count++;
                printf("%d: type: %d, value: %s\n", count, tok->type, tok->value);
            }
            printf("will print lexer: %s\n", optarg);
            break;
        case 'a':
            file_name = optarg;
            printf("will print AST %s\n", optarg);
            break;
        case 's':
            file_name = optarg;
            char *file_content = malloc(512 * sizeof(char));
            read_file(file_name, file_content, 512, 10);

            if(file_content)
                printf("file is :\n%s", file_content);

            break;
        case 'S':
            file_name = optarg;
            lexer_init(file_name);
            int idx = 0;
            while(idx < 20) {
                char c = lexer_get_next_char();
                printf("%c\n", c);
                idx++;
            }
            printf("will print asm to file %s\n", file_name);
            break;
        case '?':
            printf("Usage: casm - L|A|s|S|? <file>: %c\n", optopt);
            return 1;
        }
    }


    char *string = "name is jack";
    int idx = str_find(string, 'i');
    printf("idx: %c\n", string[idx]);

    return 42;
}
