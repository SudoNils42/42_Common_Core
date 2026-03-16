/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:00:13 by nbonnet           #+#    #+#             */
/*   Updated: 2025/10/30 14:02:55 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& src) : _input(src._input) {}

RPN& RPN::operator=(const RPN& rhs) {
    if (this != &rhs)
        _input = rhs._input;
    return *this;
}

RPN::~RPN() {}

void RPN::parse_input(std::string input) {
    _input = input;
    int operands = 0;
    int operators = 0;
    int i = 0;
    
    while (_input[i])
    {
        if (std::isdigit(_input[i]) && (_input[i + 1] == ' ' || _input[i + 1] == '\0'))
        operands++;
        else if ((_input[i] == '+' || _input[i] == '-' || _input[i] == '/' || _input[i] == '*') && (_input[i + 1] == ' ' || _input[i + 1] == '\0'))
            operators++;
        else if (!std::isspace(_input[i]))
            throw "Error: bad input";
        i++;
    }
    if (operands == 0 || operators == 0)
        throw "Error: empty input";
    if (operators + 1 != operands)
        throw "Error: wrong expression";
}
