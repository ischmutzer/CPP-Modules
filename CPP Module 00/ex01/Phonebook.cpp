#include <iostream>

std::string getFirstName() {
    return _firstName;
}
std::string getLastName() {
    return _lastName;
}
std::string getNickName() {
    return _nickname;
}

int main(int argc, char **argv)
{
    if (argc != 1) 
        std::cout << "Wrong number of arguments" << std::endl;
}