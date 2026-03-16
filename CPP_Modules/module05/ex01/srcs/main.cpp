/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:19:11 by nbonnet           #+#    #+#             */
/*   Updated: 2025/06/27 16:09:02 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../incl/Bureaucrat.hpp"
#include "../incl/Form.hpp"

int main() {
    try {
        std::cout << "=== Test 1 ===" << std::endl;
        Bureaucrat boss("Boss", 50);
        Form form("Contract", 10, 50);
        std::cout << boss << std::endl;
        std::cout << form << std::endl;
        boss.signForm(form);
        std::cout << form << std::endl;
        boss.incrementGrade();
        std::cout << boss << std::endl;
        
    }
    catch (Bureaucrat::GradeTooHighException &e) {
        std::cerr << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cerr << e.what() << std::endl;
    }
    catch (Form::GradeTooHighException &e) {
        std::cerr << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException &e) {
        std::cerr << e.what() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}