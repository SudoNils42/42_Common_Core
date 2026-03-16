/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:10:52 by nbonnet           #+#    #+#             */
/*   Updated: 2025/05/27 14:34:31 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>
# include <string>

class Harl {
  private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    
  public:
    Harl();
    ~Harl();
    void complain(std::string level);
};

#endif