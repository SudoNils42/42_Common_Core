/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:35:36 by nbonnet           #+#    #+#             */
/*   Updated: 2025/06/05 15:30:46 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Animal.hpp"

Animal::Animal() : _type("") {
    std::cout << "[Animal] Default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
    std::cout << "[Animal] Constructor with type " << _type << " called" << std::endl;
}

Animal::Animal(Animal& src) : _type(src._type) {
    std::cout << "[Animal] copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& rhs) {
    std::cout << "[Animal] operator= called" << std::endl;
    if (this != &rhs)
        _type = rhs._type;
    return *this;
}

Animal::~Animal() {
    std::cout << "[Animal] Destructor called" << std::endl;
}

void Animal::makeSound(void) const {
    std::cout << "[makeSound] WEIRRRRD animal sound" << std::endl;
}

std::string Animal::getType(void) const {
    return _type;
}