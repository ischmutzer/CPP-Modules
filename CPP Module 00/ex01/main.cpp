#include <iostream>

int main(int argc, char **argv)
{
    (void)argv;
    std::string input;

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
            for (int i = 1; true; i++) {
                if (i == 1)
                    std::cout << "Please input first name" << std::endl;
                else if (i == 2)
                    std::cout << "Please input last name" << std::endl;
                else if (i == 3) {
                    std::cout << "Please input nickname" << std::endl;
                }
                else if (i == 4) {
                    std::cout << "Please input phone number" << std::endl;
                }
                else if (i == 5) {
                    std::cout << "Please input secret" << std::endl;
                }
            } //wont work
            // std::cout << "Please input first name" <<std::endl;
            // if (!std::getline(std::cin, input))
            //     return 1 ;
            // else if (input.empty())
            //     continue ;

        }
        else if (input == "SEARCH") {
            //search
        }
        else if (input == "EXIT") {
            break ;
        }
        else {
            continue;
        }
    }
}