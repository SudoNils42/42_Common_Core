/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:59:11 by nbonnet           #+#    #+#             */
/*   Updated: 2025/07/02 14:25:38 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <fstream>

class AForm;

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat(std::string name, int grade);
        Bureaucrat (const Bureaucrat& src);
        Bureaucrat& operator=(const Bureaucrat& rhs);
        ~Bureaucrat();
        
        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        
        void signForm(AForm& form);
        void executeForm(const AForm& form) const;

        class GradeTooHighException :  public std::exception {
           public:
               const char* what() const throw();
        };     
        class GradeTooLowException :  public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
