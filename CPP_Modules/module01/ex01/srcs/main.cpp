/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:03:11 by nbonnet           #+#    #+#             */
/*   Updated: 2025/05/27 15:28:29 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Zombie.hpp"

int	main() {
	int	N = 8;
	Zombie* horde = zombieHorde(N, "Horde");
	if (!horde) {
		std::cout << "Error" << std::endl;
		return 1;
	}
	for (int i = 0; i < N; i++){
		horde[i].announce();
	}
	delete []horde;

	return 0;
}
