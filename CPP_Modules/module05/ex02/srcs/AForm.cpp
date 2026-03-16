/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:49:53 by nbonnet           #+#    #+#             */
/*   Updated: 2025/07/02 14:28:21 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/AForm.hpp"

AForm::AForm(std::string name, const int gradeMinForSign, const int gradeMinForExec) : _name(name), _signe(false), _gradeMinForSign(gradeMinForSign), _gradeMinForExec(gradeMinForExec) {
    std::cout << "[AForm] default constructor called" << std::endl;
    if (gradeMinForSign < 1 || gradeMinForExec < 1)
        throw GradeTooHighException();
    else if (gradeMinForSign > 150 || gradeMinForExec > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& src) : _name(src._name), _signe(src._signe), _gradeMinForSign(src._gradeMinForSign), _gradeMinForExec(src._gradeMinForExec) {
    std::cout << "[AForm] copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& rhs) {
    std::cout << "[AForm] operator= called" << std::endl;
    if (this != &rhs)
        _signe= rhs._signe;   
    return *this;
}

AForm::~AForm() {
    std::cout << "[AForm] default destructor called" << std::endl;
}

const std::string AForm::getName() const {
    return _name;
}

bool AForm::getSigne() const {
    return _signe;
}
int AForm::getGradeMinForSign() const {
    return _gradeMinForSign;
}

int AForm::getGradeMinForExec() const {
    return _gradeMinForExec;
}

void AForm::beSigned(Bureaucrat& src) {
    if (src.getGrade() <= _gradeMinForSign)
        _signe = true;
    else
        throw GradeTooHighException();
}

void AForm::execute(const Bureaucrat& executor) const {
    if (!_signe)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeMinForExec)
        throw GradeTooLowException();
    executeAction();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade of Aform too High!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade of Aform too Low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!" ;
}


std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << form.getName() << ", signed status: " << form.getSigne();
    return os;
}