/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:29:42 by nbonnet           #+#    #+#             */
/*   Updated: 2025/06/04 18:26:07 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Dog : public Animal {
    public:
        Dog();
        Dog(Dog& src);
        Dog& operator=(Dog& rhs);
         ~Dog();
        void makeSound(void) const;
        std::string getType(void) const;

};