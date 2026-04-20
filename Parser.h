#ifndef PARSER_H
#define PARSER_H

#include "Token.h"
#include "ASTNode.h"
#include <vector>
#include <map>

class Parser {
public:
    void parse(vector<Token> tokens);

private:
    int pos = 0;
    vector<Token> tokens;
    map<string, int> vars;

    ASTNode* parseExpression();
    ASTNode* parseTerm();
    ASTNode* parseFactor();
    int evaluateCondition();
    void executeBlock();
};

#endif