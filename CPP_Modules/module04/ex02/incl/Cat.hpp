/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:28:13 by nbonnet           #+#    #+#             */
/*   Updated: 2025/06/05 16:59:03 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain* _brain;
    public:
        Cat();
        Cat(Cat& src);
        Cat& operator=(Cat& rhs);
        ~Cat();
        void makeSound(void) const;
        std::string getType(void) const;
        Brain& getBrain() const;
};