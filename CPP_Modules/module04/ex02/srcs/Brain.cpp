/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:49:00 by nbonnet           #+#    #+#             */
/*   Updated: 2025/06/10 14:36:26 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Brain.hpp"

Brain::Brain() {
    for (int i = 0; i < 100; ++i) {
        ideas[i] = "Empty idea";
    }
    std::cout << "[Brain] default constructor called" << std::endl;
}

Brain::Brain(const Brain& src) {
    for (int i = 0; i < 100; ++i) {
        ideas[i] = src.ideas[i];
    }
    std::cout << "[Brain] copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs) {
    if (this != &rhs) {
        for (int i = 0; i < 100; ++i) {
            ideas[i] = rhs.ideas[i];
        }
    }
    std::cout << "[Brain] assignment operator called" << std::endl;
    return *this;
}

Brain::~Brain() {
    std::cout << "[Brain] destructor called" << std::endl;
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return ideas[index];
    }
    return "Invalid index";
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        ideas[index] = idea;
    }
}