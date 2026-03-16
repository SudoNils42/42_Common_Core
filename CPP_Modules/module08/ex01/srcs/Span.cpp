/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:50:00 by nbonnet           #+#    #+#             */
/*   Updated: 2025/09/05 17:15:52 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Span.hpp"

Span::Span() : _N(0) {
    std::cout << "[Span] Default constructor called" << std::endl;
}

Span::Span(unsigned int N) : _N(N) {
    _cont.reserve(N);
    std::cout << "[Span] Constructor with max '" << N <<  "' numbers called" << std::endl;
}

Span::Span(const Span& src) : _N(src._N), _cont(src._cont) {
    std::cout << "[Span] copy constructor called" << std::endl;
}

Span& Span::operator=(const Span& rhs) {
    std::cout << "[Span] operator= called" << std::endl;
    if (this != &rhs)
    {
        _N = rhs._N;
        _cont = rhs._cont;
    }
    return *this;
}

Span::~Span() {
    std::cout << "[Span] Default destructor called" << std::endl;
}

void Span::addNumber(int n) {
    if (_cont.size() >= _N)
    {
        std::cout << "Can't add number because it's full" << std::endl;
        throw std::exception();
    }
    _cont.push_back(n);
}

int Span::longestSpan() {
    if (_cont.size() < 2) 
    {
        std::cout << "Not enough elements" << std::endl;
        throw std::exception();
    } 
    
    int min = *std::min_element(_cont.begin(), _cont.end());
    int max = *std::max_element(_cont.begin(), _cont.end());
    
    return (max - min);
}

int Span::shortestSpan() {
    if (_cont.size() < 2) 
    {
        std::cout << "Not enough elements" << std::endl;
        throw std::exception();
    }
    
    std::vector<int> sorted = _cont;
    std::sort(sorted.begin(), sorted.end());
    int min_span = sorted[1] - sorted[0];
    for (unsigned int i = 1; i < sorted.size() -1; i++) {
        int span = sorted[i + 1] - sorted[i];
        if (span < min_span)
            min_span = span;
    }
    
    return min_span;
}
