/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:00:21 by nbonnet           #+#    #+#             */
/*   Updated: 2025/05/14 17:13:42 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main() {
	std::string str = "HI THIS IS BRAIN";
	std::string* strPTR = &str;
	std::string& strREF = str;

	std::cout << "memory address of str: " << &str << std::endl;
	std::cout << "memory address held by strPTR: " << strPTR << std::endl;
	std::cout << "memory address held by strREF: " << &strREF << std::endl;

	std::cout << "value of str: " << str << std::endl;
	std::cout << "value pointed by strPTR: " << *strPTR << std::endl;
	std::cout << "value pointed by strREF: " << strREF << std::endl;
	return 0;
}
