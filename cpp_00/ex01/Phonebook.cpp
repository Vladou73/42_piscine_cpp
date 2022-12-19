/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:31:38 by vnafissi          #+#    #+#             */
/*   Updated: 2022/12/19 18:33:49 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Phonebook.hpp"

Phonebook::Phonebook(void) {
	std::cout << "appel du constructeur phonebook" << std::endl;
	_idx = 0;
	return;
}

Phonebook::~Phonebook(void) {
	std::cout << "appel du destructeur phonebook" << std::endl;
	return;
}

std::string	get_user_input(void) {
	std::string		input;

	do {
		std::getline(std::cin, input);
		// std::cin.clear();
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
}

// //********** GETTERS **********//
// std::string	Phonebook::idx(void) const {
// 	return _idx;
// }

// //********** SETTERS **********//
// void	Phonebook::idx(std::string first_name) {
// 	_first_name.assign(first_name);
// }
