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

            if (currentType == "IDENTIFIER")
            {
                if (currentToken == "TABLE_CREATE")
                {
                    match("TABLE_CREATE");

                    operation = "TABLE_CREATE";

                    tablename = lexer.all_tokens[pos]; // ← Corrigido: salva nome da tabela

                    nextToken();

                    match(";");
                } 
            }
        }
        else
        {
            currentToken = "";
            currentType = "";
        }
    }
};
