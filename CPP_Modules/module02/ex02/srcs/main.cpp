/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:16:35 by nbonnet           #+#    #+#             */
/*   Updated: 2025/06/02 17:07:50 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Fixed.hpp"

int main( void ) {
// Test du main original
std::cout << "=== Tests du main original ===" << std::endl;
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;

// Tests supplémentaires
std::cout << "\n=== Tests supplémentaires ===" << std::endl;
// Test des constructeurs et affectation
Fixed c(10);           // int constructor
Fixed d(2.5f);         // float constructor
Fixed e = c;           // copy constructor and assignment
std::cout << "c (10) = " << c << std::endl;     // 10
std::cout << "d (2.5) = " << d << std::endl;    // 2.5
std::cout << "e (copie de c) = " << e << std::endl; // 10
// Test des opérateurs de comparaison
std::cout << "\nComparaisons :" << std::endl;
std::cout << "c > d : " << (c > d) << std::endl;   // 1 (true)
std::cout << "c < d : " << (c < d) << std::endl;   // 0 (false)
std::cout << "c >= d : " << (c >= d) << std::endl; // 1 (true)
std::cout << "c <= d : " << (c <= d) << std::endl; // 0 (false)
std::cout << "c == e : " << (c == e) << std::endl; // 1 (true)
std::cout << "c != d : " << (c != d) << std::endl; // 1 (true)
// Test des opérateurs arithmétiques
std::cout << "\nOpérations arithmétiques :" << std::endl;
std::cout << "c + d = " << (c + d) << std::endl;   // 12.5
std::cout << "c - d = " << (c - d) << std::endl;   // 7.5
std::cout << "c * d = " << (c * d) << std::endl;   // 25
std::cout << "c / d = " << (c / d) << std::endl;   // 4
// Test des opérateurs de décrémentation
std::cout << "\nDécrémentation :" << std::endl;
Fixed f(0.0078125f);   // _value = 2
std::cout << "f = " << f << std::endl;             // 0.0078125
std::cout << "--f = " << --f << std::endl;         // 0.00390625
std::cout << "f = " << f << std::endl;             // 0.00390625
std::cout << "f-- = " << f-- << std::endl;         // 0.00390625
std::cout << "f = " << f << std::endl;             // 0
// Test des fonctions min/max
std::cout << "\nMin/Max :" << std::endl;
Fixed g(3.14f);        // _value ≈ 803
Fixed h(2.71f);        // _value ≈ 694
std::cout << "g = " << g << ", h = " << h << std::endl; // 3.14, 2.71
std::cout << "min(g, h) = " << Fixed::min(g, h) << std::endl; // 2.71
std::cout << "max(g, h) = " << Fixed::max(g, h) << std::endl; // 3.14
std::cout << "min(const g, h) = " << Fixed::min(static_cast<const Fixed&>(g), static_cast<const Fixed&>(h)) << std::endl; // 2.71
std::cout << "max(const g, h) = " << Fixed::max(static_cast<const Fixed&>(g), static_cast<const Fixed&>(h)) << std::endl; // 3.14
// Test de getRawBits/setRawBits
std::cout << "\nRawBits :" << std::endl;
Fixed i;
i.setRawBits(1280);    // 1280 / 256 = 5
std::cout << "setRawBits(1280) : " << i << std::endl; // 5
std::cout << "getRawBits() : " << i.getRawBits() << std::endl; // 1280
// Test de toInt
std::cout << "\ntoInt :" << std::endl;
std::cout << "c.toInt() = " << c.toInt() << std::endl; // 10
std::cout << "d.toInt() = " << d.toInt() << std::endl; // 2

return 0;
}