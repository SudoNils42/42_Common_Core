/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inter.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:08:45 by nbonnet           #+#    #+#             */
/*   Updated: 2025/07/07 15:15:29 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Intern.hpp"

Intern::Intern() {
    std::cout << "[Intern] default constructor called" << std::endl;
}

Intern::Intern(const Intern&) {
    std::cout << "[Intern] copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern&) {
    std::cout << "[Intern] operator= called" << std::endl;
    return *this;
}

Intern::~Intern() {
    std::cout << "[Intern] default destructor called" << std::endl;
}

AForm* Intern::makeForm(std::string name, std::string target) const {
    std::string forms[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    for (int i = 0; i < 3; i++) {
        if (name == forms[i]) {
            std::cout << "Intern creates: " << forms[i] << std::endl;
            switch (i) {
                case 0: return new PresidentialPardonForm(target);
                case 1: return new RobotomyRequestForm(target);
                case 2: return new ShrubberyCreationForm(target);
            }
        }
    }
    throw UnknownFormException();
}


const char* Intern::UnknownFormException::what() const throw() {
    return "Unknown form name";
}