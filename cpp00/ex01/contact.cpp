#include "contact.hpp"

void Contact::set_first_name(std::string f_name)
{
    this->_first_name = f_name;
}
void Contact::set_last_name(std::string l_name)
{
    this->_last_name = l_name;
}
void Contact::set_nickname(std::string n_name)
{
    this->_nick_name = n_name;
}
void Contact::set_phone_number(std::string p_number)
{
    this->_phone_number = p_number;
}
void Contact::set_darkest_secret(std::string d_secret)
{
    this->_darkest_secret = d_secret;
}
std::string Contact::get_first_name()
{
    return this->_first_name;
}
std::string Contact::get_last_name()
{
    return this->_last_name;
}
std::string Contact::get_nickname()
{
    return this->_nick_name;
}
std::string Contact::get_phone_number()
{
    return this->_phone_number;
}
std::string Contact::get_darkest_secret()
{
    return this->_darkest_secret;
}


void Contact::print_contact()
{
    std::cout << "First name: " << this->_first_name << std::endl;
    std::cout << "Last name: " << this->_last_name << std::endl;
    std::cout << "Nickname: " << this->_nick_name << std::endl;
    std::cout << "Phone number: " << this->_phone_number << std::endl;
    std::cout << "Darkest secret: " << this->_darkest_secret << std::endl;
    std::cout << std::endl;
}
