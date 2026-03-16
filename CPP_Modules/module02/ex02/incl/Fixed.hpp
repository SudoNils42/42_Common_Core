/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:20:51 by nbonnet           #+#    #+#             */
/*   Updated: 2025/06/02 16:42:56 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed {
  private:
    int _value;
    static const int _fractionalBits; 
    
  public:
    Fixed();
    Fixed(const Fixed &src);
    Fixed(const int src);
    Fixed(const float src);
    Fixed& operator=(const Fixed &rhs);
    bool operator>(const Fixed &rhs) const;
    bool operator<(const Fixed &rhs) const;
    bool operator>=(const Fixed &rhs) const;
    bool operator<=(const Fixed &rhs) const;
    bool operator==(const Fixed &rhs) const;
    bool operator!=(const Fixed &rhs) const;
    Fixed operator+(const Fixed &rhs) const;
    Fixed operator-(const Fixed &rhs) const;
    Fixed operator*(const Fixed &rhs) const;
    Fixed operator/(const Fixed &rhs) const;
    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);
    ~Fixed();
    static const Fixed& min(Fixed &lhs, Fixed &rhs);
    static const Fixed& min(const Fixed &lhs, const Fixed &rhs);
    static const Fixed& max(Fixed &lhs, Fixed &rhs);
    static const Fixed& max(const Fixed &lhs, const Fixed &rhs);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
    
};

std::ostream& operator<<(std::ostream& os, const Fixed& src);


#endif