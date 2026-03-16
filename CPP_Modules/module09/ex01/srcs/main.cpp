/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:54:13 by nbonnet           #+#    #+#             */
/*   Updated: 2025/10/30 14:02:59 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/RPN.hpp"

void calculation(std::string input) {
    std::stack<double> stack;
    int i = 0;
    double last = 0;
    double penultimate = 0;
    
    while (input[i])
    {
        if (std::isdigit(input[i]))
            stack.push(input[i] - '0');
        else if (input[i] == '+')
        {
            if (stack.size() < 2)
                throw "Error: wrong expression";
            last = stack.top();
            stack.pop();
            penultimate = stack.top();
            stack.pop();
            stack.push(penultimate + last);
        }
        else if (input[i] == '-')
        {
            if (stack.size() < 2)
                throw "Error: wrong expression";
            last = stack.top();
            stack.pop();
            penultimate = stack.top();
            stack.pop();
            stack.push(penultimate - last);
        }
        else if (input[i] == '/')
        {
            if (stack.size() < 2)
                throw "Error: wrong expression";
            last = stack.top();
            if (last == 0)
                throw "Error: / by 0 is impossible";
            stack.pop();
            penultimate = stack.top();
            stack.pop();
            stack.push(penultimate / last);
        }
        else if (input[i] == '*')
        {
            if (stack.size() < 2)
                throw "Error: wrong expression";
            last = stack.top();
            stack.pop();
            penultimate = stack.top();
            stack.pop();
            stack.push(penultimate * last);
        }
        i++;
    }
    std::cout << stack.top() << std::endl;
}


int main (int ac, char **av) {
    if (ac != 2)
    {
        std::cerr << "Error: need one argument" << std::endl;
        return 1;
    }
    RPN rpn;
    try {
        rpn.parse_input(std::string(av[1]));
        calculation(std::string(av[1]));
    } catch (const char* e) {
        std::cerr << e << std::endl; 
    }
    
    return 0;
}