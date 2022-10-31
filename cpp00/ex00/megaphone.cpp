#include <iostream>

int main(int argc, char *argv[])
{
    std::string str;

    if (argc == 1)    
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; i < argc; i++)
        {
            str = argv[i];
            for (size_t j = 0; j < str.size(); j++)
            {
                std::putchar(std::toupper(str[j]));
            }
        }
        std::cout << std::endl;
    }
    return 0;
}