#include "Exception.hpp"

Exception::Exception(std::string message){
    this->message = message;
}

const char *Exception::what() const throw(){
    return this->message.c_str();
}
