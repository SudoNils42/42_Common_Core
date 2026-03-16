/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:12:27 by nbonnet           #+#    #+#             */
/*   Updated: 2025/05/27 14:06:02 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/replace.hpp"

Replace::Replace() {

}

Replace::~Replace() {
    
}

void Replace::setNames(std::string av1, std::string av2, std::string av3) {
    _filename = av1;
    _s1 = av2;
    _s2 = av3;
}

void Replace::process() {
    std::ifstream inFile(_filename.c_str());
    if (!inFile.is_open())
    {
        std::cout << "Error with: " << _filename << std::endl;
        return ;
    }
    std::ofstream outFile((_filename + ".replace").c_str());
    if (!outFile.is_open())
    {
        std::cout << "Error with output file" << std::endl;
        return ;
    }
    std::string content = "";
    std::string line = "";
    while(std::getline(inFile, line))
    {
        content += line;
        if (!inFile.eof())
            content += '\n';
    }
    std::string result = "";
    size_t pos = 0;
    while (pos < content.length())
    {
        size_t s1_pos = content.find(_s1, pos);
        if (s1_pos >= content.length())
        {
            result = result + content.substr(pos);
            break;
        }
        result = result + content.substr(pos, s1_pos - pos);
        result = result + _s2;
        pos = s1_pos + _s1.length();
    }
    outFile << result;
}