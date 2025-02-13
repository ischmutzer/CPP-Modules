#include <iostream>
#include "Serializer.hpp"

/* int main() {
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
}; */

int main() {
    // Test Case 1: Basic test with a Data object
    Data* original1 = new Data;
    original1->num = 42;
    original1->str = "aaaaaa!";

    std::cout << "\nTest Case 1:" << std::endl;
    std::cout << "Original pointer: " << original1 << std::endl;
    std::cout << "Original values: " << original1->num << ", " << original1->str << std::endl;

    uintptr_t serialized1 = Serializer::serialize(original1);
    std::cout << "Serialized value: " << serialized1 << std::endl;

    Data* deserialized1 = Serializer::deserialize(serialized1);
    std::cout << "Deserialized pointer: " << deserialized1 << std::endl;
    std::cout << "Deserialized values: " << deserialized1->num << ", " << deserialized1->str << std::endl;

    if (original1 == deserialized1)
        std::cout << "Success: Pointers match!" << std::endl;
    else
        std::cout << "Error: Pointers don't match!" << std::endl;

    delete original1;

    // Test Case 2: Test with another Data object
    Data* original2 = new Data;
    original2->num = 100;
    original2->str = "Hello, World!";

    std::cout << "\nTest Case 2:" << std::endl;
    std::cout << "Original pointer: " << original2 << std::endl;
    std::cout << "Original values: " << original2->num << ", " << original2->str << std::endl;

    uintptr_t serialized2 = Serializer::serialize(original2);
    std::cout << "Serialized value: " << serialized2 << std::endl;

    Data* deserialized2 = Serializer::deserialize(serialized2);
    std::cout << "Deserialized pointer: " << deserialized2 << std::endl;
    std::cout << "Deserialized values: " << deserialized2->num << ", " << deserialized2->str << std::endl;

    if (original2 == deserialized2)
        std::cout << "Success: Pointers match!" << std::endl;
    else
        std::cout << "Error: Pointers don't match!" << std::endl;

    delete original2;

    // Test Case 3: Test with a Data object initialized to zero
    Data* original3 = new Data;
    original3->num = 0;
    original3->str = "";

    std::cout << "\nTest Case 3:" << std::endl;
    std::cout << "Original pointer: " << original3 << std::endl;
    std::cout << "Original values: " << original3->num << ", " << original3->str << std::endl;

    uintptr_t serialized3 = Serializer::serialize(original3);
    std::cout << "Serialized value: " << serialized3 << std::endl;

    Data* deserialized3 = Serializer::deserialize(serialized3);
    std::cout << "Deserialized pointer: " << deserialized3 << std::endl;
    std::cout << "Deserialized values: " << deserialized3->num << ", " << deserialized3->str << std::endl;

    if (original3 == deserialized3)
        std::cout << "Success: Pointers match!" << std::endl;
    else
        std::cout << "Error: Pointers don't match!" << std::endl;

    delete original3;

    // Test Case 4: Test with a large integer value
    Data* original4 = new Data;
    original4->num = 2147483647; // Maximum 32-bit signed integer
    original4->str = "Large number";

    std::cout << "\nTest Case 4:" << std::endl;
    std::cout << "Original pointer: " << original4 << std::endl;
    std::cout << "Original values: " << original4->num << ", " << original4->str << std::endl;

    uintptr_t serialized4 = Serializer::serialize(original4);
    std::cout << "Serialized value: " << serialized4 << std::endl;

    Data* deserialized4 = Serializer::deserialize(serialized4);
    std::cout << "Deserialized pointer: " << deserialized4 << std::endl;
    std::cout << "Deserialized values: " << deserialized4->num << ", " << deserialized4->str << std::endl;

    if (original4 == deserialized4)
        std::cout << "Success: Pointers match!" << std::endl;
    else
        std::cout << "Error: Pointers don't match!" << std::endl;

    delete original4;

    // Test Case 5: Test with a negative integer value
    Data* original5 = new Data;
    original5->num = -42;
    original5->str = "Negative number";

    std::cout << "\nTest Case 5:" << std::endl;
    std::cout << "Original pointer: " << original5 << std::endl;
    std::cout << "Original values: " << original5->num << ", " << original5->str << std::endl;

    uintptr_t serialized5 = Serializer::serialize(original5);
    std::cout << "Serialized value: " << serialized5 << std::endl;

    Data* deserialized5 = Serializer::deserialize(serialized5);
    std::cout << "Deserialized pointer: " << deserialized5 << std::endl;
    std::cout << "Deserialized values: " << deserialized5->num << ", " << deserialized5->str << std::endl;

    if (original5 == deserialized5)
        std::cout << "Success: Pointers match!" << std::endl;
    else
        std::cout << "Error: Pointers don't match!" << std::endl;

    delete original5;

    // Test Case 6: Test with an empty string
    Data* original6 = new Data;
    original6->num = 123;
    original6->str = "";

    std::cout << "\nTest Case 6:" << std::endl;
    std::cout << "Original pointer: " << original6 << std::endl;
    std::cout << "Original values: " << original6->num << ", " << original6->str << std::endl;

    uintptr_t serialized6 = Serializer::serialize(original6);
    std::cout << "Serialized value: " << serialized6 << std::endl;

    Data* deserialized6 = Serializer::deserialize(serialized6);
    std::cout << "Deserialized pointer: " << deserialized6 << std::endl;
    std::cout << "Deserialized values: " << deserialized6->num << ", " << deserialized6->str << std::endl;

    if (original6 == deserialized6)
        std::cout << "Success: Pointers match!" << std::endl;
    else
        std::cout << "Error: Pointers don't match!" << std::endl;

    delete original6;

    // Test Case 7: Test with a long string
    Data* original7 = new Data;
    original7->num = 999;
    original7->str = "This is a very long string to test the serialization and deserialization process.";

    std::cout << "\nTest Case 7:" << std::endl;
    std::cout << "Original pointer: " << original7 << std::endl;
    std::cout << "Original values: " << original7->num << ", " << original7->str << std::endl;

    uintptr_t serialized7 = Serializer::serialize(original7);
    std::cout << "Serialized value: " << serialized7 << std::endl;

    Data* deserialized7 = Serializer::deserialize(serialized7);
    std::cout << "Deserialized pointer: " << deserialized7 << std::endl;
    std::cout << "Deserialized values: " << deserialized7->num << ", " << deserialized7->str << std::endl;

    if (original7 == deserialized7)
        std::cout << "Success: Pointers match!" << std::endl;
    else
        std::cout << "Error: Pointers don't match!" << std::endl;

    delete original7;

    return 0;
}