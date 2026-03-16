/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:51:40 by nbonnet           #+#    #+#             */
/*   Updated: 2025/06/10 14:38:21 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "[Dog] Default constructor called" << std::endl;
    _brain = new Brain();
}

Dog::Dog(Dog& src) : Animal(src) {
    std::cout << "[Dog] copy constructor called" << std::endl;
    _brain = new Brain(*src._brain);
}

Dog& Dog::operator=(Dog& rhs) {
    std::cout << "[Dog] operator= called" << std::endl;
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        delete _brain;
        _brain = new Brain(*rhs._brain);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "[Dog] Destructor called" << std::endl;
    delete _brain;
}

void Dog::makeSound(void) const {
    std::cout << "BARKKKKKK !!!" << std::endl;
}

std::string Dog::getType(void) const {
    return _type;
}

Brain& Dog::getBrain() const {
    return *_brain;
}