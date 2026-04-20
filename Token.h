#ifndef TOKEN_H
#define TOKEN_H

#include <string>
using namespace std;

enum TokenType {
    INT, IDENTIFIER, NUMBER,
    ASSIGN, PLUS, MINUS, MUL, DIV,
    LPAREN, RPAREN,
    SEMICOLON,
    GT, LT, EQ,
    LBRACE, RBRACE,
    END
};

struct Token {
    TokenType type;
    string value;
};

#endif