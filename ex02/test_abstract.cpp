// This file demonstrates that Animal cannot be instantiated
// Uncomment the line below to see compilation error

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "Testing that Animal is abstract..." << std::endl;

    // This line would cause a compilation error:
    // Animal* directAnimal = new Animal();
    // Error: cannot declare variable 'directAnimal' to be of abstract type 'Animal'

    // But we can still use Animal as a pointer type for polymorphism:
    Animal *dog = new Dog();
    Animal *cat = new Cat();

    dog->makeSound(); // Woof! Woof!
    cat->makeSound(); // Meow! Meow!

    delete dog;
    delete cat;

    std::cout << "\nAnimal class is successfully abstract!" << std::endl;
    return 0;
}
