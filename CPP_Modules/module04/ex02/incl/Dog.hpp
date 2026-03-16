/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:29:42 by nbonnet           #+#    #+#             */
/*   Updated: 2025/06/09 19:40:48 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain* _brain;
    public:
        Dog();
        Dog(Dog& src);
        Dog& operator=(Dog& rhs);
         ~Dog();
        void makeSound(void) const;
        std::string getType(void) const;
        Brain& getBrain() const;
};