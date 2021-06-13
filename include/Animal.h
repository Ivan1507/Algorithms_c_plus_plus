#ifndef ANIMAL_H
#define ANIMAL_H


class Animal
{
    public:
        Animal();
        virtual ~Animal();
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);

    protected:

    private:
};

#endif // ANIMAL_H
