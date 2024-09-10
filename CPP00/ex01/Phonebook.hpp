#ifndef PHONEBGOOK_HPP
#define PHONEBGOOK_HPP

#include <string>
#include "Contacts.hpp"

class Phonebook {
    private:
        Contacts contactsArray[8];
        int _index;
        int _numElements;
    public:
        Phonebook();
        ~Phonebook();
        int     getNumElements();
        int     search();
        void    addContact(std:: string firstName, std:: string lastName, std:: string nickname, std:: string phoneNumber, std:: string secret);
        void    printContacts();
        void    printContact(int index);
};

#endif