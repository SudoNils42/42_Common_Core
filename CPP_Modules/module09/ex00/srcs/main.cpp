/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:09:28 by nbonnet           #+#    #+#             */
/*   Updated: 2025/10/22 15:57:35 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/BitcoinExchange.hpp"

int main (int ac, char **av) {
    if (ac != 2)
    {
        std::cerr << "Error: need one argument" << std::endl;
        return 1;
    }
    std::ifstream file;
    file.open (av[1]);
    if (!file.is_open())
    {
        std::cerr << "Error: can't open file '" << av[1] << "'" << std::endl;
        return 1;
    }
    BitcoinExchange btc;
    btc.init_data();
    std::string line;
    getline(file, line);
    while (getline(file, line))
    {
        i = 0;
        if (btc.parse_line(line))
            btc.find_rate();
    }
    return 0;
}