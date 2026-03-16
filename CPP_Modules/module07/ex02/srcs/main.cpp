/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:15:43 by nbonnet           #+#    #+#             */
/*   Updated: 2025/08/28 18:16:18 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Array.hpp"

int main() {
    Array<int> IntTabEmpty;
    const Array<int> IntTab(3);
    // IntTab[0] = 1;
    // IntTab[1] = 2;
    // IntTab[2] = 3;
    std::cout << "size of IntTabEmpty: " << IntTabEmpty.size() << std::endl;
    std::cout << "size of IntTab: " << IntTab.size() << std::endl;
    std::cout << "content of IntTab: " << IntTab[0] << IntTab[1] << IntTab[2] << std::endl;
    
    Array<char> CharTabEmpty;
    Array<char> CharTab(3);
    CharTab[0] = 'a';
    CharTab[1] = 'b';
    CharTab[2] = 'c';
    std::cout << "size of CharTabEmpty: " << CharTabEmpty.size() << std::endl;
    std::cout << "size of CharTab: " << CharTab.size() << std::endl;
    std::cout << "content of CharTab: " << CharTab[0] << CharTab[1] << CharTab[2] << std::endl;
    
    Array<std::string> StringTab(2);
    StringTab[0] = "Hello ";
    StringTab[1] = "wolrd!";
    std::cout << "size of StringTab: " << StringTab.size() << std::endl;
    std::cout << "content of StringTab: " << StringTab[0] << StringTab[1] << std::endl;
    
    std::cout << "Test out of range..." << std::endl;
    try
    {
        StringTab[3] = "Bye!";
        std::cout << "KO! (in range)" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "OK! (out of range)" << std::endl;
    }

    return 0;
}