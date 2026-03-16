/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:12:37 by nbonnet           #+#    #+#             */
/*   Updated: 2025/06/03 18:01:23 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ClapTrap.hpp"

int main() {
    std::cout << "=== Test 1: Création et actions basiques ===" <<std::endl;
    ClapTrap bob("Bob");
    bob.attack("Jimmy");
    bob.beRepaired(2);
    bob.takeDamage(5);
    bob.attack("Jimmy");
    bob.beRepaired(13);
    std::cout << "=== Test 2: Épuisement des points d'énergie ===" << std::endl;
    ClapTrap jim("Jim");
    for (int i = 0; i < 11; ++i) {
        jim.attack("Enemy");
    }
    jim.beRepaired(5);
    std::cout << "=== Test 3: Épuisement des points de vie ===" << std::endl;
    ClapTrap alice("Alice");
    alice.takeDamage(10);
    alice.attack("Enemy");
    alice.beRepaired(5);
    alice.takeDamage(5);
    std::cout << "=== Test 4: Constructeur de copie ===" << std::endl;
    ClapTrap copyBob(bob);
    copyBob.attack("Enemy");
    copyBob.takeDamage(3);
    std::cout << "=== Test 5: Opérateur d'assignation ===" << std::endl;
    ClapTrap temp("Temp");
    temp.takeDamage(7);
    temp = bob;
    temp.attack("Enemy");
    temp.beRepaired(2);
    std::cout << "=== Test 6: Dégâts excessifs ===" << std::endl;
    ClapTrap strong("Strong");
    strong.takeDamage(100);
    strong.attack("Enemy");
    std::cout << "=== Fin des tests ===" << std::endl;
    return 0;
}