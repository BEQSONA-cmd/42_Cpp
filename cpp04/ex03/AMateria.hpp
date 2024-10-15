#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>

class AMateria
{
    protected:
        std::string _type;
    public:
        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        // virtual void use(ICharacter& target);

        // default constructor
        AMateria();
        // copy constructor
        AMateria(const AMateria &type);
        // assignment operator overload
        AMateria &operator=(const AMateria &type);
        // destructor
        virtual ~AMateria();
};

#endif