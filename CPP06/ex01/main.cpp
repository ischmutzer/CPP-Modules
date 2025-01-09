#include <iostream>
#include "Serializer.hpp"

int main() {
    Data* original = new Data;
    original->num = 42;
    original->str = "aaaaaa!";
    
    // Print original values
    std::cout << "Original pointer: " << original << std::endl;
    std::cout << "Original values: " << original->num << ", " << original->str << std::endl;
    
    // Serialize
    uintptr_t serialized = Serializer::serialize(original);
    std::cout << "Serialized value: " << serialized << std::endl;
    
    // Deserialize
    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized pointer: " << deserialized << std::endl;
    std::cout << "Deserialized values: " << deserialized->num << ", " << deserialized->str << std::endl;
    
    // Compare pointers
    if (original == deserialized)
        std::cout << "Success: Pointers match!" << std::endl;
    else
        std::cout << "Error: Pointers don't match!" << std::endl;
    
    // Clean up
    delete original;
    
    return 0;
};