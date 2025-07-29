#include <iostream>
#include "parser.hpp"
#include "DotClient.hpp"
#include <string>

class AST
{
public:
    void complete(std::string content)
    {
        Parser parser;
        DotClient dc;

        parser.parse(content);

        if (parser.operation == "TABLE_CREATE")
        {
            std::cout << "Syntax Tree:\n";
            std::cout << "  |\n";
            std::cout << "  |__OPERATION: " << parser.operation << "\n";
            std::cout << "          |\n";
            std::cout << "          |__TABLE NAME: " << parser.tablename << "\n";

            dc.initialize();
            dc.create_socket("127.0.0.1", 3006);
            dc.connect_to_server();

            std::string str = "TABLE_CREATE " + parser.tablename;
            const char *cstr = str.c_str();

            dc.send_message(cstr);
            dc.cleanup();
        }
    }
};