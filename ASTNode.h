#ifndef ASTNODE_H
#define ASTNODE_H

#include <string>
#include <stdexcept>
using namespace std;

class ASTNode {
public:
    virtual int evaluate() = 0;
};

class NumberNode : public ASTNode {
    int value;
public:
    NumberNode(int val) : value(val) {}
    int evaluate() { return value; }
};

class BinaryOpNode : public ASTNode {
    ASTNode* left;
    ASTNode* right;
    char op;
public:
    BinaryOpNode(ASTNode* l, ASTNode* r, char o)
        : left(l), right(r), op(o) {}

    int evaluate() {
        int l = left->evaluate();
        int r = right->evaluate();

        if (op == '+') return l + r;
        if (op == '-') return l - r;
        if (op == '*') return l * r;
        if (op == '/') {
            if (r == 0) throw runtime_error("Division by zero");
            return l / r;
        }
        return 0;
    }
};

#endif