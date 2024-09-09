#include <iostream>
#include <string>
#include <sstream>
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

    contactToAdd.setIndex(_index + 1);
    contactsArray[_index] = contactToAdd;
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
        std::cout << "|" << std::endl;
    }
}

void    Phonebook::printContact(int index) {
    int trueIndex = index + 1;
    std::cout << "|" << trueIndex << "|" << " ";
    alignText(contactsArray[index].getFirstName(), 8);
    std::cout << "|" << " ";
    alignText(contactsArray[index].getLastName(), 8);
    std::cout << "|" << " ";
    alignText(contactsArray[index].getNickname(), 8);
    std::cout << "|" << " ";
    alignText(contactsArray[index].getPhoneNumber(), 8);
    std::cout << "|" << " ";
    alignText(contactsArray[index].getSecret(), 8);
    std::cout << "|" << std::endl;
}

int Phonebook::search() {
    if (!getNumElements()) {
        std::cout << "Phonebook is empty" << std::endl;
        return 0;
    }
    printContacts();
    std::string index;
    std::cout << "Input index to search" << std::endl;
    while (true) {
        if (!std::getline(std::cin, index))
            return 1;
        for (int i = 0; i < getNumElements(); i++) {
            int contactIndex = contactsArray[i].getIndex();
            std::stringstream sstring;
            sstring << contactIndex;
            std::string convertedIndex = sstring.str();
            if (convertedIndex == index) {
                printContact(contactIndex - 1);
                return 0;
            }
        }
        std::cout << "Index is out of scope, please input a valid index" << std::endl;
    }
}
