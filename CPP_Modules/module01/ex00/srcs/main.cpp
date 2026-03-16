/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:03:11 by nbonnet           #+#    #+#             */
/*   Updated: 2025/05/27 15:26:10 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Zombie.hpp"

int	main() {
	Zombie z1("Stack");
	z1.announce();
	Zombie* z2 = Zombie::newZombie("Heap");
	z2->announce();
	randomChump("Stack2");
	delete z2;
	return 0;
}
