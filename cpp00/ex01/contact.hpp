#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

class Contact
{
    private:
        std::string _first_name;
        std::string _last_name;
        std::string _nick_name;
        std::string _phone_number;
        std::string _darkest_secret;
    public:
        void set_first_name(std::string f_name);
        void set_last_name(std::string l_name);
        void set_nickname(std::string n_name);
        void set_phone_number(std::string p_number);
        void set_darkest_secret(std::string d_secret);
        std::string get_first_name();
        std::string get_last_name();
        std::string get_nickname();
        std::string get_phone_number();
        std::string get_darkest_secret();
        void print_contact();
};


#endif