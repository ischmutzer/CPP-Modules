#include <iostream>
#include <fstream>
#include "Data.hpp"

//we pass a reference(&) instead of copying the string by passing the value (std::string filename)
//for efficiency -> we make it const so the ft can't change the value of &filename
int fileManipulation(const std::string& filename) {
    std::ifstream	inFile(filename.c_str());

	if (!inFile.is_open()) {
		std::cout << "Error: inFile failed at .is_open()" << std::endl;
		return 0;
	}

	std::string	newFile = filename;
	newFile.append(".replace"); // += "" -> different way to append
	std::ofstream	outFile(newFile.c_str()); // if newFile doesn't exist, it will be created and if it exists it'll be truncated
	
	if (!outFile.is_open()) {

		std::cout << "Error: outFile failed at .is_open()" << std::endl;
		return 0;
	}

	std::string	line;
	while (std::getline(inFile, line)) {
		outFile << line << std::endl;
	}

	inFile.close();
	outFile.close();
	return 1;
}

int main(int argc, char** argv) {
    if (argc == 4) {
        Data    data = Data(argv[1], argv[2], argv[3]);
        if (!fileManipulation(data.getFilename())) {
            std::cout << "Error: File failure" << std::endl;
			return 1;
        }
		return 0;
    }
    std::cout << "Error: Incorrect argument count" <<std::endl;
    return 1;
}

//1) check that filename exists //CHECK
//2) check that I have proper permissions to open -> open //CHECK
//3) read contents and, store into a str
//4) create a new file named filename.replace
//5) fill .replace with content str
//6) replace every occurrence of s1 with s2 in .replace

//no C functions allowed
//all fts of satd::string allowed except replace