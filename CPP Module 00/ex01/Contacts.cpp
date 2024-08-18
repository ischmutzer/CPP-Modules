#include "Phonebook.hpp"
//#include <iostream>

Contacts::Contacts() {
    _firstName = "";
     _lastName = "";
     _nickname = "";
     _phoneNumber = "";
     _secret = "";
}

std::string Contacts::getFirstName() {
    return _firstName;
}
std::string Contacts::getLastName() {
    return _lastName;
}
std::string Contacts::getNickName() {
    return _nickname;
}

std::string Contacts::getPhoneNumber() {
    return _phoneNumber;
}

std::string Contacts::getSecret() {
    return  _secret;
}