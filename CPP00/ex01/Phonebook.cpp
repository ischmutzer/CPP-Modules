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
    for (int i = 0; i < _numElements; i++) {
        std::cout << "|" << i << "|" << " ";
        //std::cout.write(contactsArray[i].getFirstName().c_str(), 8);
        alignText(contactsArray[i].getFirstName(), 8);
        std::cout << " " << "|" << " ";
        //std::cout.write(contactsArray[i].getLastName().c_str(), 8);
        alignText(contactsArray[i].getLastName(), 8);
        std::cout << " " << "|" << " ";
        //std::cout.write(contactsArray[i].getNickName().c_str(), 8);
        alignText(contactsArray[i].getNickname(), 8);
        std::cout << " " << "|" << " " << std::endl;
    }
}

int Phonebook::getIndex() {
    return _index;
}

// int main(int argc, char **argv)
// {
//     std::string input;

//     if (argc != 1) 
//         std::cout << "Wrong number of arguments" << std::endl;
//     std::cout << "Welcome to the phonebook" << std::endl;
//     while (true)
//     {
//         std::cout << "What do you want to do" << std::endl;
//         std::cin >> input;
//         if (input == "ADD") {
//             //add contact
//         }
//         else if (input == "SEARCH") {
//             //search
//         }
//         else if (input == "EXIT") {
//             break ;
//         }
//     }
// }