#pragma once

#include <stdint.h>
#include <string>

struct Data {
    int         num;
    std::string str;
};

class Serializer {
    public:
        static uintptr_t   serialize(Data* ptr);
        static Data*       deserialize(uintptr_t raw);
    
    protected:
    private:
        Serializer();
        Serializer(const Serializer &source);
        Serializer &operator=(const Serializer &source);
        ~Serializer();
};


//NOTES

//**MAKING THE CLASS UNABLE TO BE INSTANTIATED**
//Private Constructor vs Virtual Destructor

//->Private Constructor
//  -Purpose: Restricts object creation
//  -Effect: 1) Prevents direct instantiation of the class from outside of the class
//           2) Allows controlled object creation through static member fucntions or
//              friend classes/functions.

//->Virtual Destructor
//  -Purpose: Ensures proper cleanup of derived class objects when deleted through
//            a base class pointer.
//  -Effect: 1) When a class is intended to be used as a base class, making the 
//              destructor virtual ensures that the destructor of the derived class
//              is called when an object is deleted through a pointer to the base class.
//           2) If the destructor is not virtual, deleting a derived class object through
//              a base class ptr results in undefined behaviour.



//**SERIALIZER* CREATEINSTANCE() EXPLANATION**
//  Serializer* createInstance() { return new serializer(); };
// main() { Serializer* obj = Serializer::createInstance(); }

//obj is a ptr to Serializer because createInstance() ft dynamically allocates memory

//-> Why?
//"new" allocates memory on the heap and returns a ptr to the newly created obj. This
//allows the obj to persist beyond the scope of the ft that created it.



//** UINTPTR_T**
//-> uintptr_t is defined in <cstdint>
// represents an unsigned integer type capable of holding a ptr
// guaranteed to be large enough to store a ptr
// can safely convert a ptr to uintptr_t and back without losing any info

//Use cases of UNINTPTR_T
//1) serialization
//2)hash computation
//3) memory manipulation -> ptrs need to be represented as ints



//**ABSTRACT NON-INSTANTIABLE CLASS WITH STATIC MEMBER FUNCTIONS**
//why?
//  1) static fts in a class can act like namespaced fts that belong to the class
//  but do not require an obj to call on them

//  2) making the class non-instantiable ensures the class is used strictly as
//  a utility or an interface

//  3) abstract classes can also store const or static data members that are
//  logically grouped together

//  4) "no object creation" policy
