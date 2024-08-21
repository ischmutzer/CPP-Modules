#include <iostream>
#include <string>
#include "Phonebook.hpp"
#include "Contacts.hpp"

int    add(Phonebook *phonebook) {
    std::string input = "";
    std::string firstName = "";
    std::string lastName = "";
    std::string nickname = "";
    std::string phoneNumber = "";
    std::string secret = "";

    while (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || secret.empty()) {
        if (!std::getline(std::cin, input))
            return 1;
        else if (firstName.empty())
            firstName = input;
        else if (lastName.empty())
            lastName = input;
        else if (nickname.empty())
            nickname = input;
        else if (phoneNumber.empty()) {
            // should I check the phone number for some sort of validity?
            phoneNumber = input;
        }
        else if (secret.empty())
            secret = input;
        else {
            std::cout << "Please give an input" << std::endl; //broken
            continue ;
        }
        phonebook->addContact(firstName, lastName, nickname, phoneNumber, secret);
    }
    return 0;
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
            phonebook.printContacts();
        }
        else if (input == "EXIT") {
            break ;
        }
        else {
            continue;
        }
    }
}