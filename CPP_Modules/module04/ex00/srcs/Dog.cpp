/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:51:40 by nbonnet           #+#    #+#             */
/*   Updated: 2025/06/04 18:26:50 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "[Dog] Default constructor called" << std::endl;
}

Dog::Dog(Dog& src) : Animal(src) {
    std::cout << "[Dog] copy constructor called" << std::endl;
}

Dog& Dog::operator=(Dog& rhs) {
    std::cout << "[Dog] operator= called" << std::endl;
    if (this != &rhs)
        Animal::operator=(rhs);
    return *this;
}

Dog::~Dog() {
    std::cout << "[Dog] Destructor called" << std::endl;
}

void Dog::makeSound(void) const {
    std::cout << "BARKKKKKK !!!" << std::endl;
}

std::string Dog::getType(void) const {
    return _type;
}