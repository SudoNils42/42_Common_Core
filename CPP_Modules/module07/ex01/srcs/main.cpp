/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:15:43 by nbonnet           #+#    #+#             */
/*   Updated: 2026/02/11 13:49:11 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Iter.hpp"

template <class T>
void printElement(T& elem) {
    std::cout << elem << std::endl;
}

template <class T>
void printElement(const T& elem) {
    std::cout << elem << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    size_t len = 5;

    iter(arr, len, printElement<int>);
    
    const char carr[] = {'a', 'b', 'c'};
    iter(carr, 3, printElement<char>);

    return 0;
}