/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:09:32 by nbonnet           #+#    #+#             */
/*   Updated: 2025/10/22 15:38:14 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <limits>
#include <map>
#include <cstring>
#include <stdexcept>

extern int i;

class BitcoinExchange {
    private:
        std::map<std::string, double> _input;
        std::map<std::string, double> _data;
        
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange& operator=(const BitcoinExchange &rhs);
        ~BitcoinExchange();
        
        bool init_data();
        bool parse_line(std::string line);
        void find_rate();
};