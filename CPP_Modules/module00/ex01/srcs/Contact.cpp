/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:08:00 by nbonnet           #+#    #+#             */
/*   Updated: 2025/04/30 16:54:21 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PhoneBook.hpp"
#include "../incl/Contact.hpp"

Contact::Contact() : _first_name(""), _last_name(""), _nickname(""), _phone_number(""), _darkest_secret(""){
}

Contact::~Contact(){
}

void Contact::setFirstName(std::string input) {
	_first_name = input;
}
void Contact::setLastName(std::string input) {
	_last_name = input;
}
void Contact::setNickname(std::string input) {
	_nickname = input;
}
void Contact::setPhoneNumber(std::string input) {
	_phone_number = input;
}
void Contact::setDarkestSecret(std::string input) {
	_darkest_secret = input;
}

std::string Contact::getFirstName() const {
	return _first_name;
}

std::string Contact::getLastName() const {
	return _last_name;
}

std::string Contact::getNickname() const {
	return _nickname;
}

std::string Contact::getPhoneNumber() const {
	return _phone_number;
}

std::string Contact::getDarkestSecret() const {
	return _darkest_secret;
}
