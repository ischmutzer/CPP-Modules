#pragma

#include <cstdint>

struct Data {
    /* data */
};

class Serializer
{
    public:
        Serializer();
        Serializer(const Serializer &source);
        Serializer &operator=(const Serializer &source);
        virtual ~Serializer();

        virtual void pureVirtualFt() = 0;
        uintptr_t   serialize(Data* ptr);
        Data*       deserialize(uintptr_t raw);
    
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

