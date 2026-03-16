/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:26:45 by nbonnet           #+#    #+#             */
/*   Updated: 2025/06/05 15:30:25 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Animal {
    protected:
        std::string _type;

    public:
        Animal();
        Animal(std::string type);
        Animal(Animal& src);
        Animal& operator=(const Animal& rhs);
        virtual ~Animal();
        virtual void makeSound(void) const;
        std::string getType(void) const;
};