#ifndef PHONEBGOOK_HPP
#define PHONEBGOOK_HPP

#include <string>
#include "Contacts.hpp"

// class Contacts {
//     private:
//         std::string _firstName;
//         std::string _lastName;
//         std::string _nickname;
//         std::string _phoneNumber; //do I needx to convert it?
//         std::string _secret;

//     public:
//         Contacts();
//         Contacts(std:: string firstName, std:: string lastName, std:: string nickname, std:: string phoneNumber, std:: string secret);

//         std::string getFirstName();
//         std::string getLastName();
//         std::string getNickName();
//         std::string getPhoneNumber();
//         std::string getSecret();
//         void        setFirstName(std::string str);
//         void        setLastName(std::string str);
//         void        setNickname(std::string str);
//         void        setPhoneNumber(std::string str);
//         void        setSecret(std::string str);
// };


//las columnas deben ser 10char long -> index[0] y index[9]
//deberia ser un espacio y despues la info y si info < 10char
//se llena el resto -1 con espacios, si info > 10char at pos 8
//ponemos un punto

//ex
// | first name | last name | nickname |
// | pepe       | alohapepi.| pepito   |

class Phonebook {
    private:
        Contacts contactsArray[8];
        int _index;
        int _numElements;
    public:
        Phonebook();
        ~Phonebook();
        void    addContact(std:: string firstName, std:: string lastName, std:: string nickname, std:: string phoneNumber, std:: string secret);
        void    printContacts();
        void    searchContact();
        int     getIndex();
};

//dynamic alloc is forbidden

//max of 8 contacts -> si se agrega otro contacto
//el contacto mas antiguo es overwritten

//linked list -> si guardo los contactos en una linked list
//puedo cambiar the head y apuntarlo al siguiente contacto
//y eliminar el contacto mas antiguo y agregar el nuevo 
//contacto al final de la lista



#endif