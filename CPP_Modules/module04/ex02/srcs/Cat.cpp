/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:47:31 by nbonnet           #+#    #+#             */
/*   Updated: 2025/06/10 14:38:28 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "[Cat] Default constructor called" << std::endl;
    _brain = new Brain();
}

Cat::Cat(Cat& src) : Animal(src) {
    std::cout << "[Cat] copy constructor called" << std::endl;
    _brain = new Brain(*src._brain);
}

Cat& Cat::operator=(Cat& rhs) {
    std::cout << "[Cat] operator= called" << std::endl;
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        delete _brain;
        _brain = new Brain(*rhs._brain);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "[Cat] Destructor called" << std::endl;
    delete _brain;
}

void Cat::makeSound(void) const {
    std::cout << "MEOUWWWWWWWW !!!" << std::endl;
}

std::string Cat::getType(void) const {
    return _type;
}

Brain& Cat::getBrain() const {
    return *_brain;
}