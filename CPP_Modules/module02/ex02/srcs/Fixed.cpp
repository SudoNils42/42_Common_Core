/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:15:33 by nbonnet           #+#    #+#             */
/*   Updated: 2025/06/02 16:52:29 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed()  : _value(0) {}

Fixed::Fixed(const Fixed &src) : _value(src._value) {}

Fixed::Fixed(const int src) {
    _value = src * (1 << _fractionalBits);
}

Fixed::Fixed(const float src) {
    _value = roundf(src * (1 << _fractionalBits));
}

Fixed& Fixed::operator=(const Fixed &rhs) {
    if (this != &rhs)
        _value = rhs._value;
    return *this;
}

bool Fixed::operator>(const Fixed &rhs) const {
    if (_value > rhs._value)
        return true;
    return false;
}

bool Fixed::operator<(const Fixed &rhs) const {
    if (_value < rhs._value)
        return true;
    return false;
}

bool Fixed::operator>=(const Fixed &rhs) const {
    if (_value >= rhs._value)
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed &rhs) const {
    if (_value <= rhs._value)
        return true;
    return false;
}

bool Fixed::operator==(const Fixed &rhs) const {
        if (_value == rhs._value)
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed &rhs) const {
        if (_value != rhs._value)
        return true;
    return false;
}

Fixed Fixed::operator+(const Fixed &rhs) const {
    Fixed result;
    result._value = _value + rhs._value;
    return result;
}


Fixed Fixed::operator-(const Fixed &rhs) const {
    Fixed result;
    result._value = _value - rhs._value;
    return result;
}


Fixed Fixed::operator*(const Fixed &rhs) const {
    Fixed result;
    result._value = (_value * rhs._value) / (1 << _fractionalBits);
    return result;
}


Fixed Fixed::operator/(const Fixed &rhs) const {
    Fixed result;
    result._value = (_value * (1 << _fractionalBits) / rhs._value);
    return result;
}


Fixed& Fixed::operator++() {
    _value += 1;
    return *this;
}


Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    _value += 1;
    return temp;   
}


Fixed& Fixed::operator--() {
    _value -= 1;
    return *this;
}


Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    _value -= 1;
    return temp;
}


Fixed::~Fixed() {}


const Fixed& Fixed::min(Fixed &lhs, Fixed &rhs) {
    if (lhs._value < rhs._value)
        return lhs;
    return rhs;
}


const Fixed& Fixed::min(const Fixed &lhs, const Fixed &rhs) {
    if (lhs._value < rhs._value)
        return lhs;
    return rhs;
}


const Fixed& Fixed::max(Fixed &lhs, Fixed &rhs) {
    if (lhs._value > rhs._value)
        return lhs;
    return rhs;
}


const Fixed& Fixed::max(const Fixed &lhs, const Fixed &rhs) {
    if (lhs._value > rhs._value)
        return lhs;
    return rhs;
}

int Fixed::getRawBits(void) const {
    return _value;
}

void Fixed::setRawBits(int const raw) {
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