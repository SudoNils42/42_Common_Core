/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:11:04 by nbonnet           #+#    #+#             */
/*   Updated: 2025/10/30 14:01:45 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <string>
#include <iostream>
#include <stdexcept>

class RPN {
    private:
        std::string _input;

    public:
        RPN();
        RPN(const RPN &src);
        RPN& operator=(const RPN &rhs);
        ~RPN();

        void parse_input(std::string input);
};

