#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

class Contact
{
    public:
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string phone_number;
        std::string darkest_secret;
        void set_first_name(std::string f_name);
        void set_last_name(std::string l_name);
        void set_nickname(std::string n_name);
        void set_phone_number(std::string p_number);
        void set_darkest_secret(std::string d_secret);
        void print_contact();
};

#endif