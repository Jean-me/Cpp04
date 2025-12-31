#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
protected:
    std::string type;

public:
    Animal();
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);
    virtual ~Animal();

    virtual void makeSound() const = 0; // Pure virtual function　純粋仮想関数 - makes Animal abstract
    std::string getType() const;
};

#endif
