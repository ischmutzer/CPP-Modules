#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data {
    private:
        std::string _filename;
        std::string _s1;
        std::string _s2;

    public:
        Data();
        ~Data();
        std::string getFilename();
        std::string getS1();
        std::string getS2();
};

#endif