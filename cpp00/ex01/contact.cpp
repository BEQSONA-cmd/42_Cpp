#include "contact.hpp"

void Contact::set_first_name(std::string f_name)
{
    this->first_name = f_name;
}

void Contact::set_last_name(std::string l_name)
{
    this->last_name = l_name;
}

void Contact::set_nickname(std::string n_name)
{
    this->nick_name = n_name;
}

void Contact::set_phone_number(std::string p_number)
{
    this->phone_number = p_number;
}

void Contact::set_darkest_secret(std::string d_secret)
{
    this->darkest_secret = d_secret;
}

void Contact::print_contact()
{
    std::cout << "First name: " << this->first_name << std::endl;
    std::cout << "Last name: " << this->last_name << std::endl;
    std::cout << "Nickname: " << this->nick_name << std::endl;
    std::cout << "Phone number: " << this->phone_number << std::endl;
    std::cout << "Darkest secret: " << this->darkest_secret << std::endl;
    std::cout << std::endl;
}
