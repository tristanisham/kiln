#include <iostream>
#include <string>
// Program Files
#include "src/CLI_COMMANDS.hpp"
#include "src/Parser.hpp"

int main(int argc, char *argv[])
{
    std::cout << "Kiln v0.0.150 --debug" << std::endl;
    if (argc > 1)
    {
        std::string command = argv[1];
        if (command == "setup")
        {
            std::cout << "Heating up Kiln..." << std::endl;
            if (argc > 2)
            {
                std::string query = argv[2];
                kiln::CLICommands::make(query);

                // Build Frontend Files
            }
            else
            {
                std::cout << "Please provide a build path" << std::endl;
            }
        }
        else if (command == "fire")
        {
            std::cout << "Firing the kiln..." << std::endl;
            kiln::Parser parser;

            /*else {
                std::cout << "Please provide a build path" << std::endl;
            }*/
        }
    }
    return 0;
}
