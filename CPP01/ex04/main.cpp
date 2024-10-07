#include <iostream>

int checkFile(std::string filename) {

}

int main(int argc, char** argv) {
    if (argc == 3) {
        if (checkFile(argv[0])) {
            std::cout << "Filename failure" << std::endl;
        }
    }
    std::cout << "Incorrect argument count" <<std::endl;
    return 1;
}