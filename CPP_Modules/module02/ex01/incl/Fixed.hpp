/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:20:51 by nbonnet           #+#    #+#             */
/*   Updated: 2025/05/29 14:44:33 by nbonnet          ###   ########.fr       */
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
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
    
};

std::ostream& operator<<(std::ostream& os, const Fixed& src);


#endif