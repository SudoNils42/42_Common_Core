/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:49:27 by nbonnet           #+#    #+#             */
/*   Updated: 2025/06/27 15:18:16 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"

class AForm {
  private:
    const std::string _name;
    bool _signe;
    const int _gradeMinForSign;
    const int _gradeMinForExec;

  public:
    AForm(std::string name, const int gradeMinForSign, const int gradeMinForExec);
    AForm(const AForm& src);
    AForm& operator=(const AForm& rhs);
    ~AForm();
    
    const std::string getName() const;
    bool getSigne() const;
    int getGradeMinForSign() const;
    int getGradeMinForExec() const;
    
    void beSigned(Bureaucrat& bureaucrat);
    
    virtual void executeAction() const = 0;
    void execute(const Bureaucrat& executor) const;


    class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
    };
    class FormNotSignedException : public std::exception {
      public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);