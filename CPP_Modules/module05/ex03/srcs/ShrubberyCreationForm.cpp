/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:07:45 by nbonnet           #+#    #+#             */
/*   Updated: 2025/07/01 18:23:14 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << "[ShrubberyCreationForm] default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
    : AForm(src), _target(src._target) {
    std::cout << "[ShrubberyCreationForm] copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
    std::cout << "[ShrubberyCreationForm] operator= called" << std::endl;
    if (this != &rhs) {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "[ShrubberyCreationForm] default destructor called" << std::endl;
}

void ShrubberyCreationForm::executeAction() const { 
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not create file " << _target + "_shrubbery" << std::endl;
        return;
    }
    file << "       /\\\n"
         << "      /  \\\n"
         << "     /    \\\n"
         << "    /______\\\n"
         << "      ||||\n"
         << "      ||||\n"
         << "\n"
         << "       /\\\n"
         << "      /  \\\n"
         << "     /____\\\n"
         << "      ||||\n"
         << "      ||||\n";
    file.close();
    std::cout << "Shrubbery created in file: " << _target + "_shrubbery" << std::endl;
}