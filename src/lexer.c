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
    lexer.offset = 0;
    lexer.idx = 0;
    lexer.file_name = file_name;
    lexer.buffer = malloc(BUFFER_SIZE * sizeof(char));
    read_file(file_name, lexer.buffer, BUFFER_SIZE, lexer.offset);
    // printf("Check this out:\n%s", lexer.buffer);
}

/*
 * reads the next 512 bytes into the lexer buffer
 *
 */
void lexer_read_next_block() {
    lexer.offset++;
    read_file(lexer.file_name, lexer.buffer, BUFFER_SIZE, lexer.offset * BUFFER_SIZE);
}

/*
 * returns the next char in the buffer
 *
 */
char lexer_get_next_char() {
    char chr;

    // read the next buffer_size and reset the idx
    if(lexer.idx > BUFFER_SIZE) {
        lexer_read_next_block();
        lexer.idx = 0;
    }
    if(is_eof(lexer.buffer[lexer.idx])) {
        return -1;
    }
    else {
        chr = lexer.buffer[lexer.idx];
        lexer.idx++;
    }

    return chr;
}
