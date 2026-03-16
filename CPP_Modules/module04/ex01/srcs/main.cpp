/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:52:24 by nbonnet           #+#    #+#             */
/*   Updated: 2025/06/10 16:05:41 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Animal.hpp"
#include "../incl/Cat.hpp"
#include "../incl/Dog.hpp"
#include "../incl/WrongAnimal.hpp"
#include "../incl/WrongCat.hpp"
#include "../incl/Brain.hpp"

int main()
{
    Animal test;
    test.makeSound();
    std::cout << "===Tableau d'objets Animal ===" << std::endl;
    const int SIZE = 10;
    Animal* animals[SIZE];
    for (int i = 0; i < SIZE / 2; ++i)
        animals[i] = new Dog();
    for (int i = SIZE / 2; i < SIZE; ++i)
        animals[i] = new Cat();
    for (int i = 0; i < SIZE; ++i) {
        std::cout << "Animal " << i << " type: " << animals[i]->getType() << std::endl;
        animals[i]->makeSound();
    }
    for (int i = 0; i < SIZE; ++i)
        delete animals[i];
    
    std::cout << "=== Test de copie profonde ===" << std::endl;
    Dog original;
    original.getBrain().setIdea(0, "Chase tail");
    Dog copy = original;
    copy.getBrain().setIdea(0, "Bark loudly");
    std::cout << "Original idea: " << original.getBrain().getIdea(0) << std::endl;
    std::cout << "Copy idea: " << copy.getBrain().getIdea(0) << std::endl;
    
    std::cout << "=== Test de Brain ===" << std::endl;
    Cat myCat;
    myCat.getBrain().setIdea(0, "Catch mouse");
    myCat.getBrain().setIdea(1, "Sleep on couch");
    std::cout << "Cat idea 0: " << myCat.getBrain().getIdea(0) << std::endl;
    std::cout << "Cat idea 1: " << myCat.getBrain().getIdea(1) << std::endl;
    std::cout << "Cat idea 100: " << myCat.getBrain().getIdea(100) << std::endl;
    return 0;
}