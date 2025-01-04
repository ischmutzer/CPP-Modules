#pragma once

#include "Base.hpp"

class A : public Base {};

class B : public Base {};

class C : public Base {};


//NOTES

//-> since ABC have no additional members, they can fucntion with a default
//constructor which the compiler provides at runtime if no constructor is defined
//same with a destructor

//Empty classes in C++ are classes that don't have any member variables or
//functions defined within them. They only inherit from the base class but
//don't add any additional functionality.