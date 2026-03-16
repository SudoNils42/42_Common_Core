/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:09:59 by nbonnet           #+#    #+#             */
/*   Updated: 2025/08/16 16:36:25 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Base.hpp"

Base::~Base() {
    std::cout << "[Base] destructor called" << std::endl;
}

Base* generate(void) {
    int n;
    Base* ptr;
    
    n = std::rand() % 3;
    if (n == 0)
    {
        ptr = new A();
        return ptr;
    }
    else if (n == 1)
    {
        ptr = new B();
        return ptr;
    }
    else if (n == 2)
    {
        ptr = new C();
        return ptr;
    }
    return NULL;
}
    
void identify(Base* p) {
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "Base* p = A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "Base* p = B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "Base* p = C" << std::endl;
    else
        std::cout << "Base* p = NULL" << std::endl;
}

void identify(Base& p) {
    try {
        dynamic_cast<A&>(p);
        std::cout << "Base& p = A" << std::endl;
        return ;
    } catch (std::exception &e) {}
    
    try {
        dynamic_cast<B&>(p);
        std::cout << "Base& p = B" << std::endl;
        return ;
    } catch (std::exception &e) {}
    
    try {
        dynamic_cast<C&>(p);
        std::cout << "Base& p = C" << std::endl;
        return ;
    } catch (std::exception &e) {}
}