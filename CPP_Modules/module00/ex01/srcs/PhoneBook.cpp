/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:08:31 by nbonnet           #+#    #+#             */
/*   Updated: 2025/04/30 16:56:58 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Contact.hpp"
#include "../incl/PhoneBook.hpp"
#include <string>

PhoneBook::PhoneBook() : _i(0) {
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::addContact() {
	std::string input;

	if (_i >= 8)
		_i = 0;
	std::cout << "First name: ";
	while (std::getline(std::cin, input) && input.empty())
		std::cout << "Error: Empty field. Please enter a valid first name: ";
	_contact[_i].setFirstName(input);
	std::cout << "Last name: ";
	while (std::getline(std::cin, input) && input.empty())
		std::cout << "Error: Empty field. Please enter a valid last name: ";
	_contact[_i].setLastName(input);
	std::cout << "Nickname: ";
	while (std::getline(std::cin, input) && input.empty())
		std::cout << "Error: Empty field. Please enter a valid nickname: ";
	_contact[_i].setNickname(input);
	std::cout << "Phone number: ";
	while (std::getline(std::cin, input) && input.empty())
		std::cout << "Error: Empty field. Please enter a valid phone number: ";
	_contact[_i].setPhoneNumber(input);
	std::cout << "Darkest secret: ";
	while (std::getline(std::cin, input) && input.empty())
		std::cout << "Error: Empty field. Please enter a valid darkest secret: ";
	_contact[_i].setDarkestSecret(input);
	std::cout << "Contact successfully saved" << std::endl;
	_i++;
}


void PhoneBook::searchContact() {
	std::cout << "|   INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "|" << std::setw(8) << i << "|";
		std::string first_name = _contact[i].getFirstName();
		if (first_name.length() > 10)
			first_name = first_name.substr(0, 9) + ".";
		std::cout << std::setw(10) << first_name << "|";
		std::string last_name = _contact[i].getLastName();
		if (last_name.length() > 10)
			last_name = last_name.substr(0, 9) + ".";
		std::cout << std::setw(10) << last_name << "|";
		std::string nickname = _contact[i].getNickname();
		if (nickname.length() > 10)
			nickname = nickname.substr(0, 9) + ".";
		std::cout << std::setw(10) << nickname << "|" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Please enter contact index: ";
	std::string input;
	std::getline(std::cin, input);
	if (input.length() != 1 || !std::isdigit(input[0]))
		std::cout << "Index has to be a number between 0 and 7" << std::endl;
	else
	{
		int index;
		index = std::atoi(input.c_str());
		if (index < 0 || index > 7)
			std::cout << "Index has to be between 0 and 7" << std::endl;
		else if (_contact[index].getFirstName() == "")
			std::cout << "Please enter an existing contact" << std::endl;
		else
		{
			std::cout << "First name: " << _contact[index].getFirstName() << std::endl;
			std::cout << "Last name: " << _contact[index].getLastName() << std::endl;
			std::cout << "Nickname: " << _contact[index].getNickname() << std::endl;
			std::cout << "Phone number: " << _contact[index].getPhoneNumber() << std::endl;
			std::cout << "Darkest secret: " << _contact[index].getDarkestSecret() << std::endl;
		}
	}
}
