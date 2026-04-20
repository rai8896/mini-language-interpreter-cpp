#include "Parser.h"
#include <iostream>

using namespace std;

// ---------- FACTOR ----------
ASTNode* Parser::parseFactor() {
    Token t = tokens[pos];

    if (t.type == NUMBER) {
        pos++;
        return new NumberNode(stoi(t.value));
    }

    if (t.type == IDENTIFIER) {
        if (vars.find(t.value) == vars.end())
            throw runtime_error("Variable not declared");

        pos++;
        return new NumberNode(vars[t.value]);
    }

    if (t.type == LPAREN) {
        pos++;
        ASTNode* node = parseExpression();

        if (tokens[pos].type != RPAREN)
            throw runtime_error("Missing )");

        pos++;
        return node;
    }

    throw runtime_error("Invalid factor");
}

// ---------- TERM (* /) ----------
ASTNode* Parser::parseTerm() {
    ASTNode* node = parseFactor();

    while (tokens[pos].type == MUL || tokens[pos].type == DIV) {
        char op = tokens[pos].value[0];
        pos++;

        ASTNode* right = parseFactor();
        node = new BinaryOpNode(node, right, op);
    }

    return node;
}

// ---------- EXPRESSION (+ -) ----------
ASTNode* Parser::parseExpression() {
    ASTNode* node = parseTerm();

    while (tokens[pos].type == PLUS || tokens[pos].type == MINUS) {
        char op = tokens[pos].value[0];
        pos++;

        ASTNode* right = parseTerm();
        node = new BinaryOpNode(node, right, op);
    }

    return node;
}

// ---------- CONDITION ----------
int Parser::evaluateCondition() {
    ASTNode* left = parseExpression();

    TokenType op = tokens[pos].type;
    pos++;

    ASTNode* right = parseExpression();

    int l = left->evaluate();
    int r = right->evaluate();

    if (op == GT) return l > r;
    if (op == LT) return l < r;
    if (op == EQ) return l == r;

    throw runtime_error("Invalid condition");
}

// ---------- BLOCK ----------
void Parser::executeBlock() {

    if (tokens[pos].type != LBRACE)
        throw runtime_error("Expected {");

    pos++; // skip {

    while (tokens[pos].type != RBRACE) {

        // ---------- print ----------
        if (tokens[pos].type == IDENTIFIER && tokens[pos].value == "print") {

            pos += 2; // print (

            ASTNode* expr = parseExpression();
            cout << "Output: " << expr->evaluate() << endl;

            if (tokens[pos].type != RPAREN)
                throw runtime_error("Missing )");

            pos++; // )

            if (tokens[pos].type != SEMICOLON)
                throw runtime_error("Missing ;");

            pos++; // ;
        }

        // ---------- assignment ----------
        else if (tokens[pos].type == IDENTIFIER) {

            string var = tokens[pos].value;

            if (vars.find(var) == vars.end())
                throw runtime_error("Variable not declared");

            pos++;

            if (tokens[pos].type != ASSIGN)
                throw runtime_error("Expected =");

            pos++;

            ASTNode* expr = parseExpression();
            vars[var] = expr->evaluate();

            if (tokens[pos].type != SEMICOLON)
                throw runtime_error("Missing ;");

            pos++;
        }

        else {
            throw runtime_error("Invalid statement inside block");
        }
    }

    pos++; // skip }
}

// ---------- MAIN PARSER ----------
void Parser::parse(vector<Token> tks) {

    tokens = tks;
    pos = 0;

    try {

        while (tokens[pos].type != END) {

            // ---------- int a = 10; ----------
            if (tokens[pos].type == INT) {

                string var = tokens[pos + 1].value;
                int val = stoi(tokens[pos + 3].value);

                vars[var] = val;
                pos += 5;
            }

            // ---------- print ----------
            else if (tokens[pos].value == "print") {

                pos += 2;

                ASTNode* expr = parseExpression();
                cout << "Output: " << expr->evaluate() << endl;

                pos += 2;
            }

            // ---------- if ----------
            else if (tokens[pos].value == "if") {

                pos += 2;

                int cond = evaluateCondition();

                if (tokens[pos].type != RPAREN)
                    throw runtime_error("Missing )");

                pos++;

                if (cond) executeBlock();
                else {
                    pos++;
                    while (tokens[pos].type != RBRACE) pos++;
                    pos++;
                }
            }

            // ---------- while ----------
            else if (tokens[pos].value == "while") {

                int loopStart = pos;

                pos += 2;
                int condPos = pos;

                int cond = evaluateCondition();

                if (tokens[pos].type != RPAREN)
                    throw runtime_error("Missing )");

                pos++;

                int blockStart = pos;

                while (cond) {

                    pos = blockStart;
                    executeBlock();

                    pos = condPos;
                    cond = evaluateCondition();

                    pos = blockStart;
                }

                pos = blockStart;
                while (tokens[pos].type != RBRACE) pos++;
                pos++;
            }

            else {
                throw runtime_error("Invalid syntax");
            }
        }

    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}