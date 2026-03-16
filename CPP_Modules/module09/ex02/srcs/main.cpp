/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:30:16 by nbonnet           #+#    #+#             */
/*   Updated: 2025/11/05 18:55:17 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PmergeMe.hpp"

int jacobsthal(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 3;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

int main (int ac, char **av) {
    if (ac < 2)
    {
        std::cerr << "Error: need at least one argument" << std::endl;
        return 1;
    }
    
    PmergeMe algo;
    if (algo.init_cont(ac, av) == 1)
    {
        std::cerr << "Error: only positive numbers and under int max" << std::endl;
        return 1;
    }
    algo.display_before(ac, av);
    
    std::deque<int> deque = algo.get_deque();
    clock_t start = clock();
    ford_johnson(deque);
    clock_t end = clock();
    double deque_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    std::vector<int> vector = algo.get_vector();
    start = clock();
    ford_johnson(vector);
    end = clock();
    double vector_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    algo.display_after(deque);
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << deque_time << " us" << std::endl;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << vector_time << " us" << std::endl;
    return 0;
}