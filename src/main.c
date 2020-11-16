#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "utils.h"


int main(int argc, char** argv) {

    int option;
    char* file_name = NULL;
    while((option = getopt(argc, argv, "l:a:S:s:")) != -1){
        switch(option){
        case 'l':
            file_name = optarg;
            printf("will print lexer: %s\n", optarg);
            break;
        case 'a':
            file_name = optarg;
            printf("will print AST %s\n", optarg);
            break;
        case 's':
            file_name = optarg;
            char *file_content = read_file(file_name);
            if(file_content)
                printf("file is :\n%s", file_content);

            break;
        case 'S':
            file_name = optarg;
            printf("will print asm to file %s\n", optarg);
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
