#include <stdio.h>
#include <stdbool.h>
#include <stdbool.h>
#include <stdlib.h>

#include "lexer.h"
#include "utils.h"

struct LEXER lexer;

/*
 * check for end of file
 *
 */
bool is_eof(char ch) {
    return (ch <= 0);
}

/*
 * init lexer to and allocate buffer
 *
 */
void lexer_init(char *file_name) {
    lexer.is_eof = false;
    lexer.offset = 1;
    lexer.buffer_idx = 0;
    lexer.buffer = malloc(BUFFER_SIZE * sizeof(char));
    read_file(file_name, lexer.buffer, BUFFER_SIZE, lexer.offset);
    printf("Check this out:\n%s", lexer.buffer);
}

char lexer_get_next_char() {

    return 'A';
}
