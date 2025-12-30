#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // This should NOT compile because Animal is now abstract:
    // Animal* test = new Animal();  // ERROR: cannot instantiate abstract class

    std::cout << "=== Creating array of Animals ===" << std::endl;
    const int arraySize = 4;
    Animal *animals[arraySize];

    // Half Dogs, half Cats
    for (int i = 0; i < arraySize / 2; i++)
    {
        animals[i] = new Dog();
    }
    for (int i = arraySize / 2; i < arraySize; i++)
    {
        animals[i] = new Cat();
    }

    std::cout << "\n=== Testing sounds ===" << std::endl;
    for (int i = 0; i < arraySize; i++)
    {
        std::cout << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }

    std::cout << "\n=== Deleting array ===" << std::endl;
    for (int i = 0; i < arraySize; i++)
    {
        delete animals[i];
    }

    std::cout << "\n=== Testing deep copy ===" << std::endl;
    Dog *dog1 = new Dog();
    dog1->getBrain()->setIdea(0, "I want to chase cats!");
    dog1->getBrain()->setIdea(1, "I love bones!");

    std::cout << "\nCreating dog2 as a copy of dog1..." << std::endl;
    Dog *dog2 = new Dog(*dog1);

    std::cout << "\ndog1 ideas: " << dog1->getBrain()->getIdea(0) << std::endl;
    std::cout << "dog2 ideas: " << dog2->getBrain()->getIdea(0) << std::endl;

    std::cout << "\nChanging dog2's idea..." << std::endl;
    dog2->getBrain()->setIdea(0, "I want to play fetch!");

    std::cout << "dog1 ideas: " << dog1->getBrain()->getIdea(0) << std::endl;
    std::cout << "dog2 ideas: " << dog2->getBrain()->getIdea(0) << std::endl;

    std::cout << "\nBrain addresses (should be different):" << std::endl;
    std::cout << "dog1 brain: " << dog1->getBrain() << std::endl;
    std::cout << "dog2 brain: " << dog2->getBrain() << std::endl;

    std::cout << "\n=== Cleanup ===" << std::endl;
    delete dog1;
    delete dog2;

    return 0;
}
