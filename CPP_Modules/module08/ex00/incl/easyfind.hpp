/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:55:40 by nbonnet           #+#    #+#             */
/*   Updated: 2025/09/30 17:54:22 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

template <typename T>
void easyfind(T& haystack, int needle) {
    typename T::iterator it = std::find(haystack.begin(), haystack.end(), needle);
    if (it == haystack.end())
        throw std::exception();
    int index = std::distance(haystack.begin(), it);
    std::cout << "needle '" << needle << "' found at occurence '" << index << "'" << std::endl;
}