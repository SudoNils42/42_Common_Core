/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:12:37 by nbonnet           #+#    #+#             */
/*   Updated: 2025/06/04 13:41:50 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ClapTrap.hpp"
#include "../incl/ScavTrap.hpp"
#include <iostream>

int main() {
    std::cout << "=== Test 1: Création et actions basiques de ScavTrap ===" << std::endl;
    ScavTrap serena("Serena");
    serena.attack("Enemy");
    serena.takeDamage(30);
    serena.beRepaired(20);
    serena.guardGate();
    
    std::cout << "=== Test 2: Épuisement des points de vie ===" << std::endl;
    ScavTrap bob("Bob");
    bob.takeDamage(100);
    bob.attack("Enemy");
    bob.beRepaired(10);
    bob.guardGate();
    
    std::cout << "=== Test 3: Épuisement des points d'énergie ===" << std::endl;
    ScavTrap jim("Jim");
    for (int i = 0; i < 50; ++i) {
        jim.attack("Enemy");
    }
    jim.beRepaired(5);  
         
    std::cout << "=== Test 4: Constructeur de copie et opérateur d'assignation ===" << std::endl;
    ScavTrap copySerena(serena);
    copySerena.attack("Enemy");
    ScavTrap temp("Temp");
    temp = serena; 
    temp.attack("Enemy");
    temp.guardGate();
    
    std::cout << "=== Test 5: Comparaison avec ClapTrap ===" << std::endl;
    ClapTrap clap("Clap");
    clap.attack("Enemy");
    clap.takeDamage(5);
    clap.beRepaired(3);
    return 0;
}