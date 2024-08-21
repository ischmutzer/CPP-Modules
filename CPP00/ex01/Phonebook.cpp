#include <iostream>
#include <string>
#include "Phonebook.hpp"
#include "Contacts.hpp"

Phonebook::Phonebook() {
    index = 0;
}

Phonebook::~Phonebook() {

}

void Phonebook::addContact(std:: string firstName, std:: string lastName, std:: string nickname, std:: string phoneNumber, std:: string secret) {
    Contacts    contactToAdd(firstName, lastName, nickname, phoneNumber, secret);
    if (index < 8) {
        contactsArray[index] = contactToAdd;
        contactToAdd.setIndex(index);
        index++;
    }
    else {
        contactsArray[0] = contactToAdd;
        contactToAdd.setIndex(0);
    }
}

void    Phonebook::printContacts() {
    for (int i = 0; i < index; i++) {
        std::cout << "|" << i << "|" << " ";
        std::cout.write(contactsArray[i].getFirstName().c_str(), 8);
        std::cout << " " << "|" << " ";
        std::cout.write(contactsArray[i].getLastName().c_str(), 8);
        std::cout << " " << "|" << " ";
        std::cout.write(contactsArray[i].getNickName().c_str(), 8);
        std::cout << " " << "|" << " " << std::endl;
        if (i == index)
            break ;
    }
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