#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "=== Testing Animal hierarchy ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "\n--- Type tests ---" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << "\n--- Sound tests ---" << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();

    std::cout << "\n--- Cleanup ---" << std::endl;
    delete meta;
    delete j;
    delete i;

    std::cout << "\n=== Testing WrongAnimal hierarchy ===" << std::endl;
    const WrongAnimal* wrong_meta = new WrongAnimal();
    const WrongAnimal* wrong_cat = new WrongCat();

    std::cout << "\n--- Type tests ---" << std::endl;
    std::cout << wrong_cat->getType() << " " << std::endl;

    std::cout << "\n--- Sound tests (demonstrating wrong behavior) ---" << std::endl;
    wrong_cat->makeSound(); // will NOT output the cat sound (no virtual!)
    wrong_meta->makeSound();

    std::cout << "\n--- Cleanup ---" << std::endl;
    delete wrong_meta;
    delete wrong_cat;

    return 0;
}
