#include <iostream>
#include <string>
#include "ast.hpp"

int main() {
    AST ast;
    std::string input;

    std::cout << "All Rights to Davi Ferreira dos Reis. https://github.com/Davi-lab-pt-br/DotBase-Database\n\n";

    for (;;) {
        std::cout << "Command> ";
        std::getline(std::cin, input);  
        if (input.empty()) continue;    

        std::cout << "\n";
        ast.complete(input);
        ast.parser.pos = 0;
    }

    return 0;
}
