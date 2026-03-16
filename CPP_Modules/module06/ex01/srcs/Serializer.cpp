/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:58:29 by nbonnet           #+#    #+#             */
/*   Updated: 2025/08/14 18:45:08 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Serializer.hpp"

Serializer::Serializer() {
    std::cout << "[Serializer] constructor called" << std::endl;
}

Serializer::Serializer(const Serializer& src) {
    std::cout << "[Serializer] copy constructor called" << std::endl;
    (void)src;
}

Serializer& Serializer::operator=(const Serializer& rhs) {
    std::cout << "[Serializer] operator= called" << std::endl;
    (void)rhs;
    return *this;
}

Serializer::~Serializer() {
    std::cout << "[Serializer] destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr) {
    uintptr_t raw;
    raw = reinterpret_cast<uintptr_t>(ptr);
    return raw;
}

Data* Serializer::deserialize(uintptr_t raw) {
    Data *ptr;
    ptr = reinterpret_cast<Data*>(raw);
    return ptr;
}