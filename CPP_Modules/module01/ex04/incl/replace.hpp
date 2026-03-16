/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:56:21 by nbonnet           #+#    #+#             */
/*   Updated: 2025/05/22 18:26:50 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef REPLACE_HPP
# define REPLACE_HPP
# include <iostream>
# include <string>
# include <fstream>

class Replace {
    private:
        std::string _filename;
        std::string _s1;
        std::string _s2;
        
    public:
        Replace();
        ~Replace();
        void setNames(std::string av1, std::string av2, std::string av3);
        void process();
};

#endif
