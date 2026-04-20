#ifndef LEXER_H
#define LEXER_H

#include "Token.h"
#include <vector>

class Lexer {
public:
    vector<Token> tokenize(string code);
};

#endif