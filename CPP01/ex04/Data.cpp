#include <string>
#include "Data.hpp"

Data::Data() {
    _filename = "";
    _s1 = "";
    _s2 = "";
}

Data::Data(std::string filename, std::string s1, std::string s2) {
    _filename = filename;
    _s1 = s1;
    _s2 = s2;
}

Data::~Data() {

}

std::string Data::getFilename() {
    return  _filename;
}

std::string Data::getS1() {
    return  _s1;
}

std::string Data::getS2() {
    return _s2;
}

size_t  Data::getLengthS1() {
    size_t  length = _s1.length();
    return length;
}

size_t  Data::getLengthS2() {
    size_t  length = _s2.length();
    return length;
}
