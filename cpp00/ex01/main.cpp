#include "PhoneBook.hpp"

int main()
{
    std::string input;
    PhoneBook a;

    while (1)
    {
        std::cout << "Input : ";
        std::getline(std::cin, input);
        if(input.compare("ADD") == 0)
        {
            a.addContent();
        }
        else if (input.compare("SEARCH") == 0)
        {
            a.searchContent();
        }
        else if (input.compare("EXIT") == 0)
        {
            std::exit(0);
        }
    }
    return 0;
}