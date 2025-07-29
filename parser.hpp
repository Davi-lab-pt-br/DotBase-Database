#include <iostream>
#include <vector>
#include "lexer.hpp"

class Parser
{
public:
    Lexer lexer;
    int pos = 0;
    std::string currentToken;
    std::string currentType;

    std::string operation;
    std::string tablename;

    void nextToken()
    {
        pos++;
        if (pos < lexer.all_tokens.size())
        {
            currentToken = lexer.all_tokens[pos];
            currentType = lexer.all_types[pos];
        }
        else
        {
            currentToken = "";
            currentType = "";
        }
    }

    void match(std::string expected)
    {
        if (currentToken == expected)
        {
            nextToken();
        }
        else
        {
            throw std::runtime_error("Unexpected token, expected " + expected + ";");
        }
    }

    void parse(std::string content)
    {
        lexer.lex(content);

        if (!lexer.all_tokens.empty())
        {
            pos = 0;
            currentToken = lexer.all_tokens[pos];
            currentType = lexer.all_types[pos];

            if (currentToken == "TABLE_CREATE" && currentType == "IDENTIFIER")
            {
                match("TABLE_CREATE"); 

                tablename = currentToken; 
                nextToken();             

                if (currentToken == ";")
                {
                    match(";");                 
                    operation = "TABLE_CREATE"; 
                }
                else
                {
                    std::cout << "Expected ';' after table name.\n";
                }
            }
            else
            {
                std::cout << "Unrecognized command: " << currentToken << std::endl;
            }
        }
        else
        {
            currentToken = "";
            currentType = "";
        }
    }
};
