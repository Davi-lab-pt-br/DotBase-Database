#include <iostream>
#include <regex>
#include <vector>
#include <string>

class Lexer
{
public:
    std::vector<std::string> all_tokens;
    std::vector<std::string> all_types;

    void lex(const std::string &content)
    {
        std::regex token_types[] = {
            std::regex(R"([a-zA-Z_][a-zA-Z0-9_]*)"), // IDENTIFIER
            std::regex(R"(\d+(\.\d+)?)"),            // NUMBER
            std::regex(R"(\s+)"),                    // SPACE
            std::regex(R"(==|!=|<=|>=|&&|\|\|)"),    // RELATIONAL_LOGICAL_COMPOUND
            std::regex(R"(=|<|>|!|&|\|)"),           // RELATIONAL_LOGICAL_SIMPLE
            std::regex(R"(\+|\-|\*|\/|%)"),          // ARITHMETIC_OPERATOR
            std::regex(R"(\+\+|\-\-)"),              // UNARY_OPERATOR
            std::regex(R"(\(|\)|\{|\}|\[|\])"),      // DELIMITER
            std::regex(R"(;|,|:|\.)"),                 // PUNCTUATION
            std::regex(R"("([^"\\]|\\.)*")"),        // STRING_LITERAL
            std::regex(R"(//.*)"),                   // LINE_COMMENT
            std::regex(R"(/\*[\s\S]*?\*/)")          // BLOCK_COMMENT
        };

        std::string types[] = {
            "IDENTIFIER",
            "NUMBER",
            "SPACE",
            "RELATIONAL_LOGICAL_COMPOUND",
            "RELATIONAL_LOGICAL_SIMPLE",
            "ARITHMETIC_OPERATOR",
            "UNARY_OPERATOR",
            "DELIMITER",
            "PUNCTUATION",
            "STRING_LITERAL",
            "LINE_COMMENT",
            "BLOCK_COMMENT"};

        // Regex mestre que casa todos os tokens possíveis
        std::regex masterPattern(
            R"([a-zA-Z_][a-zA-Z0-9_]*|\d+(\.\d+)?|\s+|==|!=|<=|>=|&&|\|\||=|<|>|!|&|\||\+|\-|\*|\/|%|\+\+|\-\-|\(|\)|\{|\}|\[|\]|;|,|\.|\"([^\"\\]|\\.)*\"|//.*|/\*[\s\S]*?\*/)");

        std::smatch match;
        auto searchStart = content.cbegin();

        while (std::regex_search(searchStart, content.cend(), match, masterPattern))
        {
            std::string token = match.str();

            // Verifica qual token_type casa com a string encontrada
            bool found = false;
            for (size_t i = 0; i < sizeof(token_types) / sizeof(token_types[0]); ++i)
            {
                if (std::regex_match(token, token_types[i]))
                {
                    if (types[i] != "SPACE")
                    { // Ignora tokens SPACE
                        all_tokens.push_back(token);
                        all_types.push_back(types[i]);
                        std::cout << types[i] << ": '" << token << "'\n";
                    }
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                // Token desconhecido
                all_tokens.push_back(token);
                all_types.push_back("UNKNOWN");
                std::cout << "UNKNOWN: '" << token << "'\n";
            }

            searchStart = match.suffix().first; // Avança no texto
        }
    }
};
