#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdbool.h>
#define BUFFER_SIZE 512


typedef struct LEXER {
    bool is_eof;
    int buffer_idx;
    int offset;
    char curr_char;
    char *buffer;
    enum key_tokens {
      KEY_ASM,
      KEY_BREAK,
      KEY_CHAR,
      KEY_CONST,
      KEY_CONTINUE,
      KEY_DO,
      KEY_DOUBLE,
      KEY_ELSE,
      KEY_EXTERN,
      KEY_FLOAT,
      KEY_FOR,
      KEY_GLOBAL,
      KEY_GOTO,
      KEY_IF,
      KEY_INT,
      KEY_LONG,
      KEY_RECORD,
      KEY_RETURN,
      KEY_SHORT,
      KEY_SIZEOF,
      KEY_STATIC,
      KEY_VOID,
      KEY_WHILE,
    }key_tokens;
} lex;

bool is_eof(char ch);
void lexer_init(char *file_name);
char lexer_get_next_char();

#endif
