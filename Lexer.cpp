#include "Lexer.h"
#include <cctype>

vector<Token> Lexer::tokenize(string code) {
    vector<Token> tokens;

    for (int i = 0; i < code.size(); i++) {

        if (isspace(code[i])) continue;

        if (isalpha(code[i])) {
            string word;
            while (isalnum(code[i])) word += code[i++];
            i--;

            if (word == "int") tokens.push_back({INT, word});
            else tokens.push_back({IDENTIFIER, word});
        }

        else if (isdigit(code[i])) {
            string num;
            while (isdigit(code[i])) num += code[i++];
            i--;
            tokens.push_back({NUMBER, num});
        }

        else if (code[i] == '=' && code[i+1] == '=') {
            tokens.push_back({EQ, "=="});
            i++;
        }

        else if (code[i] == '=') tokens.push_back({ASSIGN, "="});
        else if (code[i] == '+') tokens.push_back({PLUS, "+"});
        else if (code[i] == '-') tokens.push_back({MINUS, "-"});
        else if (code[i] == '*') tokens.push_back({MUL, "*"});
        else if (code[i] == '/') tokens.push_back({DIV, "/"});
        else if (code[i] == '(') tokens.push_back({LPAREN, "("});
        else if (code[i] == ')') tokens.push_back({RPAREN, ")"});
        else if (code[i] == ';') tokens.push_back({SEMICOLON, ";"});
        else if (code[i] == '>') tokens.push_back({GT, ">"});
        else if (code[i] == '<') tokens.push_back({LT, "<"});
        else if (code[i] == '{') tokens.push_back({LBRACE, "{"});
        else if (code[i] == '}') tokens.push_back({RBRACE, "}"});
    }

    tokens.push_back({END, ""});
    return tokens;
}