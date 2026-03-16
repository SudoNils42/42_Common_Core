/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:15:40 by nbonnet           #+#    #+#             */
/*   Updated: 2025/05/27 14:38:38 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Harl.hpp"

int main()
{
    Harl harl;

    std::cout << "Testing DEBUG level:" << std::endl;
    harl.complain("DEBUG");

    std::cout << "\nTesting INFO level:" << std::endl;
    harl.complain("INFO");

    std::cout << "\nTesting WARNING level:" << std::endl;
    harl.complain("WARNING");

    std::cout << "\nTesting ERROR level:" << std::endl;
    harl.complain("ERROR");

    std::cout << "\nTesting invalid level:" << std::endl;
    harl.complain("INVALID");

    return 0;
}