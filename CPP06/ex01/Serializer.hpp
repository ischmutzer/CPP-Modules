#pragma once

#include <stdint.h>
#include <string>

struct Data {
    int         num;
    std::string str;
};

class Serializer
{
    public:
        Serializer();
        Serializer(const Serializer &source);
        Serializer &operator=(const Serializer &source);
        virtual ~Serializer() = 0;

        //virtual void pureVirtualFt() = 0;
        static uintptr_t   serialize(Data* ptr);
        static Data*       deserialize(uintptr_t raw);
    
    protected:
    private:
};


//NOTES

//-> uintptr_t is defined in <cstdint>
// represents an unsigned integer type capable of holding a ptr
// guaranteed to be large enough to store a ptr
// can safely convert a ptr to uintptr_t and back without losing any info

//Use cases of UNINTPTR_T
//1) serialization
//2)hash computation
//3) memory manipulation -> ptrs need to be represented as ints


//ABSTRACT NON-INSTANTIABLE CLASS WITH STATIC MEMBER FUNCTIONS

//why?

//1) static fts in a class can act like namespaced fts that belong to the class
//but do not require an obj to call on them

//2) making the class non-instantiable ensures the class is used strictly as
//a utility or an interface

//3) abstract classes can also store const or static data members that are
//logically grouped together

//4) "no object creation" policy
