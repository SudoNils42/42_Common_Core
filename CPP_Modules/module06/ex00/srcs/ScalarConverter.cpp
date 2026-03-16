/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:33:49 by nbonnet           #+#    #+#             */
/*   Updated: 2025/07/25 17:43:31 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << "[ScalarConverter] constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src) {
    std::cout << "[ScalarConverter] copy constructor called" << std::endl;
    (void)src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {
    std::cout << "[ScalarConverter] operator= called" << std::endl;
    (void)rhs;
    return *this;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "[ScalarConverter] destructor called" << std::endl;
}



bool isSpecial(std::string input) {
    if (input.empty()) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return(true);
    }
    if (input == "nan" || input == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return(true);
    }
    if (input == "+inf" || input == "+inff" || input == "inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return(true);
    }
    if (input == "-inf" || input == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return(true);
    }
    return(false);
}

bool isChar(std::string input) {
    if (input.length() == 1 && !std::isdigit(input[0]))
        return (true);
    return (false);    
}

void toChar(std::string input) {
    char c = input[0];
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

bool isInt(std::string input) {
    int i = 0;
    if (input[0] == '+' || input[0] == '-')
        i = 1;
    int len = input.length();
    for (; i < len; i++) {
        if (!std::isdigit(input[i]))
            return (false);
    }
    if (len == 1 && !std::isdigit(input[0]))
        return (false);
    return (true);
}

void toInt(std::string input) {
    long value = std::atol(input.c_str());
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;   
    }
    if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max()) {
        char c = static_cast<char>(value);
        if (std::isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
        std::cout << "char: impossible" << std::endl;
    std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

bool isFloat(std::string input) {
    if (input == "-f" || input == "+f")
        return false;
    int len = input.length() - 1;
    if (input[len] != 'f')
        return (false);
    bool hasDecimal = false;
    int i = 0;
    if (input[0] == '+' || input[0] == '-')
        i = 1;
    for (; i < len; i++) {
        if (input[i] == '.') {
            if (hasDecimal)
                return (false);
            hasDecimal = true;
        }
        else if (!std::isdigit(input[i]))
            return (false);
    }
    if (hasDecimal == false)
        return (false);
    return (true);
}

void toFloat(std::string input) {
    std::string str = input.substr(0, input.length() - 1);
    double value = std::atof(str.c_str());
    if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max()) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max() && value == static_cast<int>(value)) {
        char c = static_cast<char>(value);
        if (std::isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
        std::cout << "char: impossible" << std::endl;
    if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max() && value == static_cast<long>(value))
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

bool isDouble(std::string input) {
    int len = input.length();
    bool hasDecimal = false;
    int i = 0;
    if (input[0] == '+' || input[0] == '-')
        i = 1;
    for (; i < len; i++) {
        if (input[i] == '.') {
            if (hasDecimal)
                return (false);
            hasDecimal = true;
        }
        else if (!std::isdigit(input[i]))
            return (false);
    }
    if (hasDecimal == false)
        return (false);
    return (true);
}

void toDouble(std::string input) {
    double value = std::atof(input.c_str());
    if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max() && value == static_cast<int>(value)) {
        char c = static_cast<char>(value);
        if (std::isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
        std::cout << "char: impossible" << std::endl;
    if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max() && value == static_cast<long>(value))
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    if (value >= -std::numeric_limits<float>::max() && value <= std::numeric_limits<float>::max()) {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    }
    else
        std::cout << "float: impossible" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convert(std::string input) {
    if (isSpecial(input))
        return ;
    else if (isChar(input))
        toChar(input);
    else if (isInt(input))
        toInt(input);
    else if (isFloat(input))
        toFloat(input);
    else if (isDouble(input))
        toDouble(input);
    else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
    return ;
}