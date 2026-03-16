/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 18:04:19 by nbonnet           #+#    #+#             */
/*   Updated: 2025/09/17 17:10:03 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/easyfind.hpp"

int main() {
    
    std::cout << "---Test with a vector container---" << std::endl;
    int needle = 5;
    std::vector<int> vec_haystack;
    vec_haystack.push_back(1);
    vec_haystack.push_back(2);
    vec_haystack.push_back(3);
    vec_haystack.push_back(4);
    vec_haystack.push_back(5);
    vec_haystack.push_back(6);
    vec_haystack.push_back(7);
    vec_haystack.push_back(8);
    try {
    easyfind(vec_haystack, needle);
    } catch (std::exception &e) {
        std::cout << "needle '" << needle << "' not found in vec_haystack" << std::endl;
    }
    needle = 9;
    try {
    easyfind(vec_haystack, needle);
    } catch (std::exception &e) {
        std::cout << "needle '" << needle << "' not found in vec_haystack" << std::endl;
    }
    needle = 5;
    std::vector<int> vec_haystackEmpty;
    try {
    easyfind(vec_haystackEmpty, needle);
    } catch (std::exception &e) {
        std::cout << "needle '" << needle << "' not found in vec_haystack" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "---Test with a list container---" << std::endl;
    needle = 5;
    std::list<int> lst_haystack;
    lst_haystack.push_back(1);
    lst_haystack.push_back(2);
    lst_haystack.push_back(3);
    lst_haystack.push_back(4);
    lst_haystack.push_back(5);
    lst_haystack.push_back(6);
    lst_haystack.push_back(7);
    lst_haystack.push_back(8);
    try {
    easyfind(lst_haystack, needle);
    } catch (std::exception &e) {
        std::cout << "needle '" << needle << "' not found in lst_haystack" << std::endl;
    }
    needle = 9;
    try {
    easyfind(lst_haystack, needle);
    } catch (std::exception &e) {
        std::cout << "needle '" << needle << "' not found in lst_haystack" << std::endl;
    }
    needle = 5;
    std::list<int> lst_haystackEmpty;
    try {
    easyfind(lst_haystackEmpty, needle);
    } catch (std::exception &e) {
        std::cout << "needle '" << needle << "' not found in lst_haystack" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "---Test with a deque container---" << std::endl;
    needle = 5;
    std::deque<int> deq_haystack;
    deq_haystack.push_back(1);
    deq_haystack.push_back(2);
    deq_haystack.push_back(3);
    deq_haystack.push_back(4);
    deq_haystack.push_back(5);
    deq_haystack.push_back(6);
    deq_haystack.push_back(7);
    deq_haystack.push_back(8);
    try {
        easyfind(deq_haystack, needle);
    } catch (std::exception &e) {
        std::cout << "needle '" << needle << "' not found in deq_haystack" << std::endl;
    }
    needle = 9;
    try {
        easyfind(deq_haystack, needle);
    } catch (std::exception &e) {
        std::cout << "needle '" << needle << "' not found in deq_haystack" << std::endl;
    }
    needle = 5;
    std::deque<int> deq_haystackEmpty;
    try {
        easyfind(deq_haystackEmpty, needle);
    } catch (std::exception &e) {
        std::cout << "needle '" << needle << "' not found in deq_haystackEmpty" << std::endl;
    }
    return 0;
}