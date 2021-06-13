#include "Animal.h"

Animal::Animal()
{
    //ctor
}

Animal::~Animal()
{
    //dtor
}

Animal::Animal(const Animal& other)
{
    //copy ctor
}

Animal& Animal::operator=(const Animal& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
