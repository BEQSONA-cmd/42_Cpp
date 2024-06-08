#include "phonebook.hpp"

int main(void)
{
    Phonebook phone;
    std::cout << "Command should be ADD, SEARCH or EXIT" << std::endl;
    while(1)
    {
        std::string line;
        std::cout << "Enter a command: ";
        std::getline(std::cin, line);
        // if(line == "add_more")
        //     phone.add_more(7);
        if (line == "EXIT")
            break;
        else if (line == "ADD")
            phone.add();
        else if (line == "SEARCH")
            phone.search();
        else
            std::cout << "Command should be ADD, SEARCH or EXIT" << std::endl;
    }
    return 0;
}
