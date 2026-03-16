/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:35:36 by nbonnet           #+#    #+#             */
/*   Updated: 2025/06/05 15:31:03 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("") {
    std::cout << "[WrongAnimal] Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
    std::cout << "[WrongAnimal] Constructor with type " << _type << " called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal& src) : _type(src._type) {
    std::cout << "[WrongAnimal] copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
    std::cout << "[WrongAnimal] operator= called" << std::endl;
    if (this != &rhs)
        _type = rhs._type;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "[WrongAnimal] Destructor called" << std::endl;
}

void WrongAnimal::makeSound(void) const {
    std::cout << "[makeSound] WEIRRRRD WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType(void) const {
    return _type;
}