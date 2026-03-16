/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:49:59 by nbonnet           #+#    #+#             */
/*   Updated: 2025/05/29 15:09:04 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed()  : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) : _value(src._value) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int src) {
    std::cout << "Int constructor called" << std::endl;
    _value = src * (1 << _fractionalBits);
}

Fixed::Fixed(const float src) {
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(src * (1 << _fractionalBits));
}

Fixed& Fixed::operator=(const Fixed &rhs) {
    std::cout << "Copy assignment operator [=] called" << std::endl;
    if (this != &rhs)
        _value = rhs._value;
    return *this;
    
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}

float Fixed::toFloat(void) const {
    return _value / (float)(1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _value / (1 << _fractionalBits);

}

std::ostream& operator<<(std::ostream& os, const Fixed& src) {
    os << src.toFloat();
    return os;
}