/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:30:04 by nbonnet           #+#    #+#             */
/*   Updated: 2025/11/05 18:54:55 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <deque>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <algorithm>

class PmergeMe {
    private:
        std::deque<int> _deque;
        std::vector<int> _vector;
        
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe& operator=(const PmergeMe &rhs);
        ~PmergeMe();

        int init_cont(int ac, char **av);
        void display_before(int ac, char **av);
        void display_after(std::deque<int> deque);
        std::deque<int>& get_deque();
        std::vector<int>& get_vector();

};

int jacobsthal(int n);

template <typename Container>
void ford_johnson(Container &container) {
    if (container.size() <= 1)
        return;
    Container main;
    Container pend;
   
    int odd = -1;
    if (container.size() % 2 == 1)
    {
        odd = container.back();
        container.pop_back();
    }
   
    typename Container::iterator it = container.begin();
    while (it != container.end())
    {
        int a = *it;
        it++;
        int b = *it;
        main.push_back(std::min(a, b));
        pend.push_back(std::max(a, b));
        it++;

    }

    ford_johnson(main);
    int n = 1;
    while (!pend.empty())
    {
        int j = jacobsthal(n);
        if (j >= static_cast<int>(pend.size()))
            break;
        typename Container::iterator it = pend.begin();
        for (int i = 0; i < j; i++)
            it++;
        int val = *it;
        pend.erase(it);
        main.insert((std::lower_bound(main.begin(), main.end(), val)), val);
        n++;
    }
    if (odd != -1)
        pend.push_back(odd);
    while (!pend.empty())
    {
        int val = pend.back();
        pend.pop_back();
        main.insert((std::lower_bound(main.begin(), main.end(), val)), val);
    }
    container = main;
}