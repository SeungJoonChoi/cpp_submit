#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->contents[0] = "fist name";
        this->contents[1] = "last name";
        this->contents[2] = "nickname";
        this->contents[3] = "phone number";
        this->contents[4] = "darkest secret";
        this->amount = 0;
        for(int i = 0; i < 8; i++)
            this->contacts[i].setIdx(i);
}

int PhoneBook::_isInvalidChar(std::string &str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!std::isprint(str[i]))
            return 1;
    }
    return 0;
}

void PhoneBook::addContent(void)
{
    std::string str;

    for(int i = 0; i < 5; i++)
    {
        std::cout << this->contents[i] << " : ";
        std::getline(std::cin, str);
        while(str.size() == 0 || _isInvalidChar(str))
        {
            std::cout << this->contents[i] << " : ";
            std::getline(std::cin, str);
        }
        this->contacts[this->amount % 8].setInfo(i, str);
    }
    this->amount++;
}

void PhoneBook::searchContent()
    {
        int idx;

        if (this->amount == 0)
        {
            std::cout << "Empty" << std::endl;
            return ;
        }
        for(int i = 0; i < this->amount && i < 8; i++)
        {
            std::cout << std::setw(10) << i << "|"; 
            this->contacts[i].display_idx();
        }
        while (1)
        {
            std::cout << "Choose index : ";
            std::cin >> idx;
            if (std::cin.fail() || idx < 0 || idx > 7 || idx >= this->amount)
            {
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                std::cout << "Invalid index." << std::endl;
            }
            else
            {
                std::cin.ignore(32767, '\n');
                this->contacts[idx].display_contents();
                break ;
            }
        }
    }