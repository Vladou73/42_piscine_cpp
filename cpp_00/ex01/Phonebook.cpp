/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:31:38 by vnafissi          #+#    #+#             */
/*   Updated: 2022/12/20 15:46:08 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include "Phonebook.hpp"

Phonebook::Phonebook(void) {
	// std::cout << "appel du constructeur phonebook" << std::endl;
	_idx = 0;
	return;
}

Phonebook::~Phonebook(void) {
	// std::cout << "appel du destructeur phonebook" << std::endl;
	return;
}

std::string	get_user_input(void) {
	std::string		input;

	do {
		std::getline(std::cin, input);
	} while (input.empty());
	return input;
}

void	Phonebook::add_contact(void) {
	Contact			contact;

	if (this->_idx == 8)
		this->_idx = 0;

	std::cout << "enter first name :" << std::endl;
	contact.first_name(get_user_input());

	std::cout << "enter last name :" << std::endl;
	contact.last_name(get_user_input());

	std::cout << "enter nickname :" << std::endl;
	contact.nickname(get_user_input());

	std::cout << "enter phone number :" << std::endl;
	contact.phone_number(get_user_input());

	std::cout << "enter darkest secret :" << std::endl;
	contact.darkest_secret(get_user_input());

	this->contact_list[_idx] = contact;
	_idx++;
}


void	print_formatted_str(std::string str) {
	if (str.length() < 9)
		std::cout << "|" << std::setw(10) << str;
	else
		std::cout << "|" << str.substr(0, 9) + ".";
}

void	Phonebook::search_contact(void) const {
	int	index;

	for (int i = 0; i < 8; i++) {
		std::cout << std::setw(10) << i + 1;;
		print_formatted_str(this->contact_list[i].first_name());
		print_formatted_str(this->contact_list[i].last_name());
		print_formatted_str(this->contact_list[i].nickname());
		std::cout << "|" << std::endl;
	}

	std::cout << "Please enter the index of the contact you want to see." << std::endl;
	std::cin.clear();
	std::cin >> index;
	if (std::cin.fail() || index < 1 || index > 8) {
		std::cout << "please enter an existing index" << std::endl;
		std::cin.clear();
		std::cin.ignore(10000,'\n');
		return;
	}
	std::cin.clear();
	std::cin.ignore(10000,'\n');

	std::cout << contact_list[index - 1].first_name() << std::endl;
	std::cout << contact_list[index - 1].last_name() << std::endl;
	std::cout << contact_list[index - 1].nickname() << std::endl;
	std::cout << contact_list[index - 1].phone_number() << std::endl;
	std::cout << contact_list[index - 1].darkest_secret() << std::endl;
}
