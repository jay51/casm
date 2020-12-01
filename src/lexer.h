#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdbool.h>


typedef struct lex {
    bool is_eof;
    int idx;
    char curr_char;
    char *buffer;
    char *file_name;
} LEXER;

typedef struct token {
    char *value;
    enum type {
        //empty token
        NONE,
        //end of file
        END_OF_FILE,
        // identifier
        IDENTIFIER,
        //keywords
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
        //literals
        LIT_DECIMAL,
        LIT_OCTAL,
        LIT_HEX,
        LIT_BIN,
        LIT_FLOAT,
        LIT_CHAR,
        LIT_STRING,
        //assignment operators
        ASSGN,
        ASSGN_ADD,
        ASSGN_SUB,
        ASSGN_MUL,
        ASSGN_DIV,
        ASSGN_MOD,
        ASSGN_BIT_OR,
        ASSGN_BIT_AND,
        ASSGN_BIT_EX_OR,
        ASSGN_LSHIFT,
        ASSGN_RSHIFT,
        //arithmetic operators
        ARTHM_ADD,
        ARTHM_SUB,
        ARTHM_MUL,
        ARTHM_DIV,
        ARTHM_MOD,
        //comparison operators
        COMP_LESS,
        COMP_LESS_EQ,
        COMP_GREAT,
        COMP_GREAT_EQ,
        COMP_EQ,
        COMP_NOT_EQ,
        //logical opertors
        LOG_AND,
        LOG_OR,
        LOG_NOT,
        //bitwise operators
        BIT_AND,
        BIT_OR,
        BIT_EXOR,
        BIT_COMPL,
        BIT_LSHIFT,
        BIT_RSHIFT,
        //pointer operator
        PTR_OP,
        //address of operator
        ADDROF_OP,
        //arrow operator ->
        ARROW_OP,
        //increment/decrement operators
        INCR_OP,
        DECR_OP,
        //miscellaneous operators
        DOT_OP,
        COMMA_OP,
        COLON_OP,
        CURLY_OPEN_BRACKET,
        CURLY_CLOSE_BRACKET,
        PARENTH_OPEN,
        PARENTH_CLOSE,
        SQUARE_OPEN_BRACKET,
        SQUARE_CLOSE_BRACKET,
        SEMICOLON,
    } type;

} TOKEN;

TOKEN *make_token(int type, char *value);
TOKEN *identifier();
TOKEN *literal();

void lexer_init(char *file_name);
char lexer_get_next_char();
TOKEN *lexer_get_next_token();

bool is_eof(char ch);

#endif
