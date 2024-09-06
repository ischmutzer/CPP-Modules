#include <iostream>
#include <string>
#include "Phonebook.hpp"
#include "Contacts.hpp"

Phonebook::Phonebook() {
    _index = 0;
    _numElements = 0;
}

Phonebook::~Phonebook() {

}

int Phonebook::getNumElements() {
    return _numElements;
}

void Phonebook::addContact(std:: string firstName, std:: string lastName, std:: string nickname, std:: string phoneNumber, std:: string secret) {
    Contacts    contactToAdd(firstName, lastName, nickname, phoneNumber, secret);

    contactsArray[_index] = contactToAdd;
    contactToAdd.setIndex(_index);
    _index++;
    if (_index >= 8)
        _index = 0;
    if (_numElements < 8)
        _numElements++;
}

void    alignText(const std::string& str, std::size_t width) {
    if (str.length() > width) {
        std::cout.write(str.c_str(), width - 1);
        std::cout << ".";
    }
    else {
        std::string paddedStr = str;
        int diff = 10 - str.length();
        for (int i = 0; i < diff; i++) {
            paddedStr += " ";
        }
        std::cout.write(paddedStr.c_str(), 8);
    }
}

void    Phonebook::printContacts() {
    for (int i = 0, j = 1; i < _numElements; i++, j++) {
        std::cout << "|" << j << "|" << " ";
        alignText(contactsArray[i].getFirstName(), 8);
        std::cout << "|" << " ";
        alignText(contactsArray[i].getLastName(), 8);
        std::cout << "|" << " ";
        alignText(contactsArray[i].getNickname(), 8);
        std::cout << "|" << " " << std::endl;
    }
}

void    Phonebook::searchContact() {
    //a;
}
