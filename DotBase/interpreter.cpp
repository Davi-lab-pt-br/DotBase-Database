#include <iostream>
#include <string>
#include "ast.hpp"

int main(){
    AST ast;

    std::string input;

    std::cout <<
        "╭━━━╮╱╱╭╮╭━━╮╱╱╱╱╱╱╱╱╱╱ ╭━━━┳╮╱╱╱╱╭╮╭╮\n" <<
        "╰╮╭╮┃╱╭╯╰┫╭╮┃╱╱╱╱╱╱╱╱╱╱ ┃╭━╮┃┃╱╱╱╱┃┃┃┃\n" <<
        "╱┃┃┃┣━┻╮╭┫╰╯╰┳━━┳━━┳━━╮ ┃╰━━┫╰━┳━━┫┃┃┃\n" <<
        "╱┃┃┃┃╭╮┃┃┃╭━╮┃╭╮┃━━┫┃━┫ ╰━━╮┃╭╮┃┃━┫┃┃┃\n" <<
        "╭╯╰╯┃╰╯┃╰┫╰━╯┃╭╮┣━━┃┃━┫ ┃╰━╯┃┃┃┃┃━┫╰┫╰╮\n" <<
        "╰━━━┻━━┻━┻━━━┻╯╰┻━━┻━━╯ ╰━━━┻╯╰┻━━┻━┻━╯\n" <<
        "\n"<<
        "All Rigths to Davi Ferreira dos Reis. https://github.com/Davi-lab-pt-br/DotBase-Database"<< 
        "\n";

    for(;;){
        std::cin >> input;
        std::cout << "\n";
        ast.complete(input);
    }
    return 0;
}