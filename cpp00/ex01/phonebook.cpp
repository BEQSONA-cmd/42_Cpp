#include "phonebook.hpp"

Phonebook::Phonebook()
{
    this->index = 0;
    this->contact_count = 0;
}

void Phonebook::add_more(int n)
{
    int i = 0;
    std::string name;
    std::cout << "name: ";
    std::getline(std::cin, name);
    while (i < n)
    {
        contacts[this->index].first_name = name;
        contacts[this->index].last_name = name;
        contacts[this->index].nick_name = name;
        contacts[this->index].phone_number = name;
        contacts[this->index].darkest_secret = name;
        this->index = (this->index + 1) % 8;
        if (this->contact_count < 8)
            this->contact_count++;
        i++;
    }
}

void Phonebook::add()
{
    std::cout << "Enter first name: ";
    std::getline(std::cin, contacts[this->index].first_name);
    std::cout << "Enter last name: ";
    std::getline(std::cin, contacts[this->index].last_name);
    std::cout << "Enter nickname: ";
    std::getline(std::cin, contacts[this->index].nick_name);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, contacts[this->index].phone_number);
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, contacts[this->index].darkest_secret);
    this->index = (this->index + 1) % 8;
    if (this->contact_count < 8)
        this->contact_count++;
}


int ft_atoi(std::string str)
{
    if(str[0] < '0' || str[0] > '7' || str.length() > 1)
        return (-1);
    int n = str[0] - '0';
    return (n);
}

void cut_print_string(std::string str)
{
    int i = 0;
    while(i < 10 && i < (int)str.length())
    {
        std::cout << str[i];
        i++;
    }
    while(i < 10)
    {
        std::cout << " ";
        i++;
    }
}

void Phonebook::display_contacts()
{
    std::cout << std::endl;
    std::cout << "     [index|first name|last  name| nickname ]" << std::endl << std::endl;
    for (int i = 0; i < this->contact_count; i++)
    {
        int display_index = (this->index - this->contact_count + i + 8) % 8;
        std::cout << "     [  " << i << "  |";
        cut_print_string(contacts[display_index].first_name);
        std::cout << "|";
        cut_print_string(contacts[display_index].last_name);
        std::cout << "|";
        cut_print_string(contacts[display_index].nick_name);
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;
}

void Phonebook::search()
{
    display_contacts();
    std::cout << "Enter an index: ";
    std::string line;
    std::getline(std::cin, line);
    int i = ft_atoi(line);
    if (i < 0 || i >= this->contact_count)
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    int contact_index = (this->index - this->contact_count + i + 8) % 8;
    contacts[contact_index].print_contact();
}