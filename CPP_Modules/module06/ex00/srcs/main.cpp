/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:53:02 by nbonnet           #+#    #+#             */
/*   Updated: 2025/07/09 13:15:35 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ScalarConverter.hpp"

int main(int ac, char** av) {
    if (ac != 2)
    {
        std::cout << "please provide 1 argument" << std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);
    return 0;
}