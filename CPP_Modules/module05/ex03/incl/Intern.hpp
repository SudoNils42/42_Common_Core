/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:08:18 by nbonnet           #+#    #+#             */
/*   Updated: 2025/07/07 14:09:55 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

class Intern {
    public:
        Intern();
        Intern(const Intern& src);
        Intern& operator=(const Intern& rhs);
        ~Intern();

        AForm* makeForm(std::string name, std::string target) const;

        class UnknownFormException : public std::exception {
            public:
                const char* what() const throw();
        };
};