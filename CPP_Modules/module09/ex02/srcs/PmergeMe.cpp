/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:30:34 by nbonnet           #+#    #+#             */
/*   Updated: 2025/11/05 18:56:17 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& src) : _deque(src._deque), _vector(src._vector) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
    if (this != &rhs)
    {
        _deque = rhs._deque;
        _vector = rhs._vector;

    }
    return *this;
}

PmergeMe::~PmergeMe() {}

int PmergeMe::init_cont(int ac, char **av) {
    int i = 1;
    while (i < ac)
    {
        double tmp = std::atoi(av[i]);
        if (tmp < 0 || (tmp == 0 && av[i][0] != '0') || tmp > std::numeric_limits<int>::max())
            return 1;
        
        _deque.push_back(std::atoi(av[i]));
        _vector.push_back(std::atoi(av[i]));
        i++;
    }
    return 0;
}

std::deque<int>& PmergeMe::get_deque() {
    return _deque;
}

std::vector<int>& PmergeMe::get_vector() {
    return _vector;
}


void PmergeMe::display_before(int ac, char **av) {
    std::cout << "Before:";
    int max = 6;
    if (ac > 6)
        max = 5;
    int i = 1;
    while (i != max && i < ac)
    {
        std::cout << " " << av[i];
        i++;
    }
    if (max == 5)
        std::cout << " [...]";
    std::cout << std::endl;
}

void PmergeMe::display_after(std::deque<int> deque) {
    std::cout << "After: ";
    int max = 6;
    
    if (deque.size() > 5)
        max = 5;
    int i = 1;
    while (/* i != max &&  */i != static_cast<int>(deque.size()) + 1)
    {
        std::cout << " " << deque[i - 1];
        i++;
    }
    if (max == 5)
        std::cout << " [...]";
    std::cout << std::endl;
}