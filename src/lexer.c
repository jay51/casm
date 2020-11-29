#include <stdio.h>
#include <stdbool.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "lexer.h"
#include "utils.h"

LEXER lexer;

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

    chr = lexer.buffer[lexer.idx];
    lexer.idx++;

    return chr;
}

TOKEN *make_token(int type, char *value) {
    TOKEN *tok = (TOKEN*) malloc(sizeof(TOKEN));
    tok->type = type;
    tok->value = value;
    return tok;
}


/*
 * tokenize var names
 *
 * @return token  type identifier and value for var
 */
TOKEN *identifier() {
    int start = lexer.idx - 1;
    char chr;

    while((chr = lexer_get_next_char())) {
        switch(chr) {
            case '_':
            case '$':
            case 'a'...'z':
            case 'A'...'Z':
                continue;
        }
        break;
    }
    char *str = malloc(sizeof(char) * lexer.idx - start);
    memcpy(str, &lexer.buffer[start], lexer.idx - start - 1);
    str[lexer.idx - start - 1] = '\0';
    lexer.idx--;
    return make_token(IDENTIFIER, str);
}

/*
 * tokenize string literal, char literal and number literal
 *
 * @return token
 */
TOKEN *literal() {
    int start = lexer.idx -1;

    // char literal
    if(lexer.buffer[start] == '\''){
        char *char_literal = malloc(sizeof(char) * 2);
        memcpy(char_literal, &lexer.buffer[lexer.idx], 1);
        char_literal[2] = '\0';
        lexer_get_next_char(); // skip char
        lexer_get_next_char(); // skip '
        return make_token(LIT_CHAR, char_literal);
    }

    // number literal
    if(isdigit(lexer.buffer[start])) {
        while(isdigit(lexer_get_next_char())) {
        }

        char *number = malloc(sizeof(char) * lexer.idx - start);
        memcpy(number, &lexer.buffer[start], lexer.idx - start);
        number[lexer.idx - start] = '\0';
        lexer.idx--;
        return make_token(LIT_DECIMAL, number);
    }

    // string literal
    if(lexer.buffer[start] == '"') {
        start++; // so I don't include the "
        while(lexer_get_next_char() != '"') {
        }
        char *str_literal = malloc(sizeof(char) * lexer.idx - start);
        memcpy(str_literal, &lexer.buffer[start], lexer.idx - start - 1);
        str_literal[lexer.idx - start - 1] = '\0';
        return make_token(LIT_STRING, str_literal);
    }

    return NULL;
}


TOKEN *lexer_get_next_token() {

    char chr;
    while((chr = lexer_get_next_char()) != -1) {
        switch(chr) {
            case '_':
            case '$':
            case 'a'...'z':
            case 'A'...'Z':
                return identifier();

            case '"':
            case '\'':
            case '0'...'9':
                return literal();

            case ' ':
            case '\t':
                continue;
        }
    }
    return make_token(END_OF_FILE, NULL);
}
