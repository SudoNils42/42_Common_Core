/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:19:11 by nbonnet           #+#    #+#             */
/*   Updated: 2025/07/02 15:35:30 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../incl/Bureaucrat.hpp"
#include "../incl/AForm.hpp"
#include "../incl/ShrubberyCreationForm.hpp"
#include "../incl/RobotomyRequestForm.hpp"
#include "../incl/PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>

int main() {
    srand (time(NULL));
    try {
        std::cout << "=== Test ShrubberyCreationForm ===" << std::endl;
        Bureaucrat bob("Bob", 137);
        ShrubberyCreationForm shrub("home");
        std::cout << bob << std::endl;
        std::cout << shrub << std::endl;
        bob.signForm(shrub);    //doit avoir min 145
        bob.executeForm(shrub); //doit avoir min 137.
        
        std::cout << "=== Test RobotomyRequestForm ===" << std::endl;
        Bureaucrat alice("Alice", 40);
        RobotomyRequestForm robot("robot1");
        std::cout << alice << std::endl;
        std::cout << robot << std::endl;
        alice.signForm(robot); // doit avoir min 72
        for (int i = 0; i < 5; i++) {
        alice.executeForm(robot); //doit avoir min 45 (et 1 chance sur 2)
        }
        
        std::cout << "=== Test PresidentialPardonForm ===" << std::endl;
        Bureaucrat boss("Boss", 5);
        PresidentialPardonForm pardon("criminal");
        std::cout << boss << std::endl;
        std::cout << pardon << std::endl;
        boss.signForm(pardon); // doit avoir min 25
        boss.executeForm(pardon); //doit avoir min 5
        
        std::cout << "=== Test Failure (unsigned form) ===" << std::endl;
        Bureaucrat low("Low", 150);
        ShrubberyCreationForm shrub2("garden");
        low.executeForm(shrub2); // devrait echouer (non signed)
    } 
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
       