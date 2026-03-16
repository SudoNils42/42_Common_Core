/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:53:30 by nbonnet           #+#    #+#             */
/*   Updated: 2025/10/22 15:56:46 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/BitcoinExchange.hpp"

int i = 0;

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) : _input(src._input), _data(src._data) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
    if (this != &rhs)
    {
        _data = rhs._data;
        _input = rhs._input;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::init_data() {
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cerr << "Error: can't open the csv file" << std::endl;
        return false;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::string date = line.substr(0, 10);
        double rate = std::atof(line.substr(11).c_str());
        _data[date] = rate;
    }
    return true;
}


int get_year(std::string line) {
    int year;
    
    while (i < 4)
    {
        if (!isdigit(line[i]))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            return -1;
        }
        i++;
    }
    year = atoi((line.substr(0, 4)).c_str());
    if (line[i] != '-')
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return -1;
    }
    i++;
    return year;
}

int get_month(std::string line) {
    int month;
    
    while (i < 7)
    {
        if (!isdigit(line[i]))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            return -1;
        }
        i++;
    }
    month = atoi((line.substr(5, 2)).c_str());
    if (line[i] != '-')
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return -1;
    }
    i++;
    return month;
}

int get_day(std::string line) {
    int day;
    
    while (i < 10)
    {
        if (!isdigit(line[i]))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            return -1;
        }
        i++;
    }
    day = atoi((line.substr(8, 2)).c_str());
    if (line[i] != ' ' || line[i + 1] != '|' || line[i + 2] != ' ')
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return -1;
    }
    i += 2;
    return day;
}

double get_value(std::string line) {
    double value;
    
    value = std::atof((line.substr(i ,line.size() - i).c_str()));
    i++;
    if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return -1;
    }
    if (value > 2147483647)
    {
        std::cerr << "Error: too large number." << std::endl;
        return -1;
    }
    else if (value > 1000)
    {
        std::cerr << "Error: value too high." << std::endl;
        return -1;
    }
    int flag = 0;
    while (line[i] != '\0')
    {   
        if (!isdigit(line[i]) && (line[i] != '.' || flag == 1))
        {
            std::cerr << "Error: bad value." << std::endl;
            return -1;
        }
        if (line[i] == '.')
            flag = 1;
        i++;
    }
    return value;
}

bool check_date(int year, int month, int day) {
    
    if (year < 2009 || year > 2025)
    {
        std::cerr << "Error: bad date." << std::endl;
        return false;
    }
    if (month < 1 || month > 12)
    {
        std::cerr << "Error: bad date." << std::endl;
        return false;
    }
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day < 1 || day > 31)
        {
            std::cerr << "Error: bad date." << std::endl;
            return false;
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day < 1 || day > 30)
        {
            std::cerr << "Error: bad date." << std::endl;
            return false;
        }
    }
    if (month == 2)
    {
        if (year % 4 == 0)
        {
            if (day < 1 || day > 29)
            {
                std::cerr << "Error: bad date." << std::endl;
                return false;
            }
        }
        else if (day < 1 || day > 28)
        {
            std::cerr << "Error: bad date." << std::endl;
            return false;
        }
    }
    return true;
}

std::string date_to_str(int year, int month, int day) {
    
    std::string date_str = "";
    char buffer[5];
    sprintf(buffer, "%d", year);
    date_str += buffer;
    date_str += "-";
    memset(buffer, 0, sizeof(buffer));
    if (month < 10) date_str += "0";
    sprintf(buffer, "%d", month);
    date_str += buffer;
    date_str += "-";
    memset(buffer, 0, sizeof(buffer));
    if (day < 10) date_str += "0";
    sprintf(buffer, "%d", day);
    date_str += buffer;
    return date_str;
}

bool BitcoinExchange::parse_line(std::string line) {
    int year = get_year(line);
    if (year == -1)
        return false;
    int month = get_month(line);
    if (month == -1)
        return false;
    int day = get_day(line);
    if (day == -1)
        return false;
    double value = get_value(line);
    if (value == -1)
        return false;
    if (!check_date(year, month, day))
        return false;
    std::string date_str = date_to_str(year, month, day);
    _input[date_str] = value;
    return true;
}

void  BitcoinExchange::find_rate() {
    std::map<std::string, double>::iterator input_it = _input.end();
    input_it--;
    std::map<std::string, double>::const_iterator data_it = _data.lower_bound(input_it->first);
    if (data_it == _data.begin())
    {
        std::cerr << "Error: no rate" << std::endl;
        return ;
    }
    if (data_it == _data.end() || data_it->first != input_it->first)
        data_it--;
    std::cout << input_it->first << " => " << input_it->second << " = " << input_it->second * data_it->second << std::endl;
}