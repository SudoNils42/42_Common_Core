/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:12:37 by nbonnet           #+#    #+#             */
/*   Updated: 2025/06/04 14:32:22 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ClapTrap.hpp"
#include "../incl/ScavTrap.hpp"
#include "../incl/FragTrap.hpp"
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
    std::cout << "=== Test 5: Création et actions basiques de FragTrap ===" << std::endl;
    FragTrap fraggy("Fraggy");
    fraggy.attack("Enemy");
    fraggy.takeDamage(40);
    fraggy.beRepaired(25);
    fraggy.highFivesGuys();
    std::cout << "=== Test 6: Épuisement des points de vie pour FragTrap ===" << std::endl;
    FragTrap alice("Alice");
    alice.takeDamage(100);
    alice.attack("Enemy");
    alice.beRepaired(10);
    alice.highFivesGuys();
    std::cout << "=== Test 7: Épuisement des points d'énergie pour FragTrap ===" << std::endl;
    FragTrap charlie("Charlie");
    for (int i = 0; i < 100; ++i) {
        charlie.attack("Enemy");
    }
    charlie.attack("Enemy");
    charlie.beRepaired(5);
    charlie.highFivesGuys();
    std::cout << "=== Test 8: Constructeur de copie et opérateur d'assignation pour FragTrap ===" << std::endl;
    FragTrap copyFraggy(fraggy);
    copyFraggy.attack("Enemy");
    FragTrap tempFrag("TempFrag");
    tempFrag = fraggy;
    tempFrag.attack("Enemy");
    tempFrag.highFivesGuys();
    std::cout << "=== Test 9: Comparaison avec ClapTrap et ScavTrap ===" << std::endl;
    ClapTrap clap("Clap");
    clap.attack("Enemy");
    clap.takeDamage(5);
    clap.beRepaired(3);
    ScavTrap scav("Scavvy");
    scav.attack("Enemy");
    scav.guardGate();
    FragTrap frag("Fraggy2");
    frag.attack("Enemy");
    frag.highFivesGuys();
    return 0;
}