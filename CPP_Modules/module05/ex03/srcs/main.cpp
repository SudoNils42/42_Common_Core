/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:19:11 by nbonnet           #+#    #+#             */
/*   Updated: 2025/07/07 15:17:48 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../incl/Bureaucrat.hpp"
#include "../incl/AForm.hpp"
#include "../incl/ShrubberyCreationForm.hpp"
#include "../incl/RobotomyRequestForm.hpp"
#include "../incl/PresidentialPardonForm.hpp"
#include "../incl/Intern.hpp"
#include <ctime>
#include <cstdlib>

int main() {
    srand (time(NULL));
    try {
        std::cout << "=== Test Intern ===" << std::endl;
        
        Intern intern;
        AForm* form;
        Bureaucrat bob("Bob", 100);
        Bureaucrat alice("Alice", 30);
        Bureaucrat boss("Boss", 2);
        std::cout << std::endl;
        
        form = intern.makeForm("shrubbery creation", "garden");
        bob.signForm(*form);
        bob.executeForm(*form);
        delete form;
        std::cout << std::endl;
        
        form = intern.makeForm("robotomy request", "dig holes");
        std::cout << *form << std::endl;
        alice.signForm(*form);
        alice.executeForm(*form);
        delete form;
        std::cout << std::endl;
        
        form = intern.makeForm("presidential pardon", "Trump");
        std::cout << *form << std::endl;
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
        std::cout << std::endl;
        
        std::cout << "=== Test Invalid Form ===" << std::endl;
        form = intern.makeForm("invalid form", "target");
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
       