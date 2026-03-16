/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:49:53 by nbonnet           #+#    #+#             */
/*   Updated: 2025/06/27 16:07:17 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Form.hpp"

Form::Form(std::string name, const int gradeMinForSign, const int gradeMinForExec) : _name(name), _signe(false), _gradeMinForSign(gradeMinForSign), _gradeMinForExec(gradeMinForExec) {
    std::cout << "[Form] default constructor called" << std::endl;
    if (gradeMinForSign < 1 || gradeMinForExec < 1)
        throw GradeTooHighException();
    else if (gradeMinForSign > 150 || gradeMinForExec > 150)
        throw GradeTooLowException();
}

Form::Form(Form& src) : _name(src._name), _signe(src._signe), _gradeMinForSign(src._gradeMinForSign), _gradeMinForExec(src._gradeMinForExec) {
    std::cout << "[Form] copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& rhs) {
    std::cout << "[Form] operator= called" << std::endl;
    if (this != &rhs)
        _signe= rhs._signe;   
    return *this;
}

Form::~Form() {
    std::cout << "[Form] default destructor called" << std::endl;
}

const std::string Form::getName() const {
    return _name;
}

bool Form::getSigne() const {
    return _signe;
}
int Form::getGradeMinForSign() const {
    return _gradeMinForSign;
}

int Form::getGradeMinForExec() const {
    return _gradeMinForExec;
}

void Form::beSigned(Bureaucrat& src) {
    if (src.getGrade() <= _gradeMinForSign)
        _signe = true;
    else
        throw GradeTooHighException();
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade of form too High!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade of form too Low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << form.getName() << ", signed status: " << form.getSigne();
    return os;
}