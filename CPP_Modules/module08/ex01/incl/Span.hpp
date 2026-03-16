/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:03:52 by nbonnet           #+#    #+#             */
/*   Updated: 2025/09/05 17:19:59 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>


class Span {
    private:
        unsigned int _N;
        std::vector<int> _cont;
        
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& src);
        Span& operator=(const Span& rhs);
        ~Span();

        void addNumber(int n);
        int shortestSpan();
        int longestSpan();

        template <typename T>
        void addNumbers(T first, T last);
};

template <typename T>
void Span::addNumbers(T first, T last) {
    size_t d = std::distance(first, last);
    if (_cont.size() + d > _N) 
    {
        std::cout << "Not enough place" << std::endl;
        throw std::exception();
    }
    _cont.insert(_cont.end(), first, last);
}