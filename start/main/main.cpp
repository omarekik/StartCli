#include <iostream>
#include <locale>
#include "StartupConfig.h"

int main(int argc, char* argv[])
{
    try 
    {
        if (const auto config = optionsToStartupConfig(argc, argv)) 
        {
            if(config->m_Create)
            {
                std::cout << "The width is " << config->m_Width << "\n";
            }
            else
            {
                std::cout << "Create option should be called\n";
            }
        }
    }
    catch(std::exception& e) {
        std::cerr << e.what() << "\n";
    }
}