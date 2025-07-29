#include <iostream>
#include <string>
#include <locale>   // para std::locale
#include "ast.hpp"

int main() {
    AST ast;
    std::string input;

    std::cout << "All Rights to Davi Ferreira dos Reis. https://github.com/Davi-lab-pt-br/DotBase-Database\n\n";

    for (;;) {
        std::cout << "Command> ";
        std::getline(std::cin, input);  // lê linha inteira, incluindo espaços
        if (input.empty()) continue;    // opcional: ignora linha vazia

        std::cout << "\n";
        ast.complete(input);
    }

    return 0;
}

