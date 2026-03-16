/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:49:27 by nbonnet           #+#    #+#             */
/*   Updated: 2025/08/11 15:17:18 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"

class Form {
  private:
    const std::string _name;
    bool _signe;
    const int _gradeMinForSign;
    const int _gradeMinForExec;

  public:
    Form(std::string name, const int gradeMinForSign, const int gradeMinForExec);
    Form(Form& src);
    Form& operator=(const Form& rhs);
    ~Form();
    
    const std::string getName() const;
    bool getSigne() const;
    int getGradeMinForSign() const;
    int getGradeMinForExec() const;
    
    void beSigned(Bureaucrat& bureaucrat);
    
    class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Form& form);