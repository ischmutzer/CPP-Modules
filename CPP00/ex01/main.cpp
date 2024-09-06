#include <iostream>
#include <string>
#include <sstream>
#include "Phonebook.hpp"
#include "Contacts.hpp"

int    add(Phonebook *phonebook) {
    std::string firstName, lastName, nickname, phoneNumber, secret;

    while (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || secret.empty()) {
        if (firstName.empty()) {
            std::cout << "Input first name" << std::endl;
            if (!std::getline(std::cin, firstName))
                return 1;
        }
        else if (lastName.empty()) {
            std::cout << "Input last name" << std::endl;
            if (!std::getline(std::cin, lastName))
                return 1;
        }
        else if (nickname.empty()) {
            std::cout << "Input nickname" << std::endl;
            if (!std::getline(std::cin, nickname))
                return 1;
        }
        else if (phoneNumber.empty()) {
            // should I check the phone number for some sort of validity?
            std::cout << "Input phonenumber" << std::endl;
            if (!std::getline(std::cin, phoneNumber))
                return 1;
        }
        else if (secret.empty()) {
            std::cout << "Input darkest secret" << std::endl;
            if (!std::getline(std::cin, secret))
                return 1;
        }
    }
    phonebook->addContact(firstName, lastName, nickname, phoneNumber, secret);
    return 0;
}

void search(Phonebook *phonebook) {
    if (!phonebook->getNumElements()) {
        std::cout << "Phonebook is empty" << std::endl;
        return;
    }
    phonebook->printContacts();
}

int main(int argc, char **argv)
{
    (void)argv;
    std::string input;
    Phonebook   phonebook;

    if (argc != 1) 
        std::cout << "Wrong number of arguments" << std::endl;
    std::cout << "Welcome to the phonebook" << std::endl;
    while (true)
    {
        std::cout << "Please input ADD, SEARCH or EXIT" << std::endl;
        if (!std::getline(std::cin, input)) {
            return 1 ;
        }
        if (input == "ADD") {
            if (add(&phonebook))
                return 1;
        }
        else if (input == "SEARCH") {
            search(&phonebook);
            //while (1) {
                //if (phonebook.getIndex() == 0)
                // std::cout << "Input desired index to search" << std::endl;
                // if (!std::getline(std::cin, input))
                //     return 1;
                // for (int i = 0; i < 8; i++) {
                //     std::stringstream object;

                //     object << i;
                //     std::string converted_int = object.str();
                //     // if (input == converted_int)
                //     //     //phonebook.printContact(i);
                //     // else {
                //     //     std::cout << "Invalid input" << std::endl;
                //     //     break ;
                //     // }
                // }
            //}
        }
        else if (input == "EXIT") {
            break ;
        }
        else {
            continue;
        }
    }
}