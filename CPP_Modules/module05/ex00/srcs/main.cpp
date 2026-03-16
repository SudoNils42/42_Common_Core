/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:26:59 by nbonnet           #+#    #+#             */
/*   Updated: 2025/06/27 16:19:32 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"

int main() {
    try
    {
        std::cout << "=== Test 1 ===" << std::endl;
        Bureaucrat employee("Employee", 50);
        std::cout << employee << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "=== Test 2 ===" << std::endl;
        Bureaucrat boss("Boss", -1);
        std::cout << boss << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "=== Test 3 ===" << std::endl;
        Bureaucrat intern("Intern", 151);
        std::cout << intern << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "=== Test 4 ===" << std::endl;
        Bureaucrat worker("Worker", 2);
        std::cout << worker << std::endl;
        worker.incrementGrade();
        std::cout << worker << std::endl;
        worker.incrementGrade();
        std::cout << worker << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "=== Test 5 ===" << std::endl;
        Bureaucrat worker("Worker", 149);
        std::cout << worker << std::endl;
        worker.decrementGrade();
        std::cout << worker << std::endl;
        worker.decrementGrade();
        std::cout << worker << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "=== Test 6 ===" << std::endl;
        Bureaucrat original("Original", 100);
        Bureaucrat copy(original);
        std::cout << "Original : " << original << std::endl;
        std::cout << "Copie : " << copy << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "=== Test 7 ===" << std::endl;
        Bureaucrat worker1("Worker1", 75);
        Bureaucrat worker2("Worker2", 25);
        std::cout << worker1 << ", " << worker2 << std::endl;
        worker2 = worker1;
        std::cout << worker1 << ", " << worker2 << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}