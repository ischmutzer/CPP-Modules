#include "Phonebook.hpp"
#include "Contacts.hpp"
//#include <iostream>

Contacts::Contacts() {
    _firstName = "";
     _lastName = "";
     _nickname = "";
     _phoneNumber = "";
     _secret = "";
     _index = 0;
}

Contacts::Contacts(std:: string firstName, std:: string lastName, std:: string nickname, std:: string phoneNumber, std:: string secret) {
    _firstName = firstName;
    _lastName = lastName;
    _nickname = nickname;
    _phoneNumber = phoneNumber;
    _secret = secret;
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

void    Contacts::setFirstName(std::string _firstName) {
    this->_firstName = _firstName;
}

void    Contacts::setLastName(std::string str) {
    _lastName = str;
}

void    Contacts::setNickname(std::string str) {
    _nickname = str;
}

void    Contacts::setPhoneNumber(std::string str) {
    _phoneNumber = str;
}

void    Contacts::setSecret(std::string str) {
    _secret = str;
}

void    Contacts::setIndex(int index) {
    _index = index;
}
