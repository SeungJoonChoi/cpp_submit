#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    std::string contents[5];
    int amount;
    static int _isInvalidChar(std::string &str);
public:
    PhoneBook();
    void addContent();
    void searchContent();
};

#endif