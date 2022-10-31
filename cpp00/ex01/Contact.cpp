#include "Contact.hpp"

void Contact::setIdx(int i)
{
    this->idx = i;
}

void Contact::setInfo(int i, std::string str)
{
    this->info[i] = str;
}

std::string Contact::getInfo(int i)
{
    return(this->info[i]);
}

void Contact::display_idx(void)
{
    for (int i = 0; i < 3; i++)
        {
            if (this->info[i].length() > 10)
            {
                std::cout << this->info[i].substr(0, 9) << ".|";
            }
            else
                std::cout << std::setw(10) <<  this->info[i] << "|";
        }
        std::cout << std::endl;
}

void Contact::display_contents(void)
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << this->info[i] << std::endl;
    }
}