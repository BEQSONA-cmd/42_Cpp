#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
    this->name = "ShrubberyCreationForm";
    this->is_signed = false;
    this->signGrade = 145;
    this->execGrade = 137;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberycreationform) : AForm(shrubberycreationform)
{
    this->operator=(shrubberycreationform);
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubberycreationform)
{
    this->name = shrubberycreationform.name;
    this->is_signed = shrubberycreationform.is_signed;
    this->signGrade = shrubberycreationform.signGrade;
    this->execGrade = shrubberycreationform.execGrade;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    // default destructor
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
{
    this->target = target;
    this->name = "ShrubberyCreationForm";
    this->is_signed = false;
    this->signGrade = 145;
    this->execGrade = 137;
}

void ShrubberyCreationForm::action() const
{

    std::string filename = this->getTarget() + "_shrubbery";
    std::ofstream file(filename.c_str());

    std::cout << GREEN "Created ASCII tree in file: " BLUE << filename << RESET << std::endl;

    file << "      *      " << std::endl;
    file << "     ***     " << std::endl;
    file << "    *****    " << std::endl;
    file << "   *******   " << std::endl;
    file << "  *********  " << std::endl;
    file << " *********** " << std::endl;
    file << "     | |     " << std::endl;
    file << "     | |     " << std::endl;

    file.close();
}
