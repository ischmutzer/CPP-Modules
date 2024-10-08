#ifndef CONTACTS_HPP
#define CONTACTS_HPP

#include <string>

class Contacts {
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber; //do I needx to convert it?
        std::string _secret;
        int _index;

    public:
        Contacts();
        Contacts(std:: string firstName, std:: string lastName, std:: string nickname, std:: string phoneNumber, std:: string secret);
        ~Contacts();

        std::string getFirstName();
        std::string getLastName();
        std::string getNickname();
        std::string getPhoneNumber();
        std::string getSecret();
        int         getIndex();
        void        setFirstName(std::string str);
        void        setLastName(std::string str);
        void        setNickname(std::string str);
        void        setPhoneNumber(std::string str);
        void        setSecret(std::string str);
        void        setIndex(int index);
};

#endif