/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:47:02 by nbonnet           #+#    #+#             */
/*   Updated: 2025/08/20 18:15:03 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <class T>
void iter(T* array, size_t len, void (*f)(T&)) {
    for (size_t i = 0; i < len; i++)
        f(array[i]);
}

template <class T>
void iter(const T* array, size_t len, void (*f)(const T&)) {
    for (size_t i = 0; i < len; ++i)
        f(array[i]);
}