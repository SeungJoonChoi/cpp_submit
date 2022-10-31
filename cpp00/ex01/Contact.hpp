#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact
{
private:
    std::string info[5];
    int idx;
public:
    void setIdx(int i);
    void setInfo(int i, std::string str);
    std::string getInfo(int i);
    void display_idx(void);
    void display_contents(void);
};

#endif