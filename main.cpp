#include <iostream>
#include "Lexer.h"
#include "Parser.h"

using namespace std;

int main() {
    cout << "Enter code (type END to stop):\n";

    string line, code;
    while (true) {
        getline(cin, line);
        if (line == "END") break;
        code += line + " ";
    }

    Lexer lexer;
    vector<Token> tokens = lexer.tokenize(code);

    Parser parser;
    parser.parse(tokens);

    return 0;
}