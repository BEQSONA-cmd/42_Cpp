#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "contact.hpp"
#include <iostream>
#include <string>

class Phonebook
{
    private:
        Contact contacts[8];
        int index;
        int contact_count;
    public:
        void add();
        void add_more(int n);
        void search();
        void display_contacts();
        Phonebook();
};

#endif