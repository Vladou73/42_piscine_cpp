/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:31:38 by vnafissi          #+#    #+#             */
/*   Updated: 2022/12/21 14:26:12 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include "Phonebook.hpp"

Phonebook::Phonebook(void) {
	// std::cout << "appel du constructeur phonebook" << std::endl;
	_idx = 0;
	_nb_contacts = 0;
	return;
}

Phonebook::~Phonebook(void) {
	// std::cout << "appel du destructeur phonebook" << std::endl;
	return;
}

std::string	ft_find_replace(std::string input, std::string old_str, std::string new_str)
{
	size_t pos = input.find(old_str); // Get first occurrence
	while (pos != std::string::npos) // Repeat till end is reached
	{
		input.replace(pos, old_str.size(), new_str); // replace with new string
		pos = input.find(old_str, pos + new_str.size()); // Get next occurrence
	}
	return input;
}

std::string	get_user_input(void) {
	std::string		input;
	do {
		std::getline(std::cin, input);
		if (std::cin.fail())
			std::exit(1);
	} while (input.empty());
	return ft_find_replace(input, "\t", " ");
}

void	Phonebook::add_contact(void) {
	Contact			contact;

	if (_idx == 8)
		_idx = 0;

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

	_contact_list[_idx] = contact;
	_idx++;
	if (_nb_contacts < 8)
		_nb_contacts++;
}


void	print_formatted_str(std::string str) {
	if (str.length() < 9)
		std::cout << "|" << std::setw(10) << str;
	else
		std::cout << "|" << str.substr(0, 9) + ".";
}

void	Phonebook::search_contact(void) const {
	int	index;

	if (_nb_contacts == 0) {
		std::cout << "no contacts found." << std::endl;
		return;
	}

	for (int i = 0; i < _nb_contacts; i++) {
		std::cout << std::setw(10) << i + 1;;
		print_formatted_str(_contact_list[i].first_name());
		print_formatted_str(_contact_list[i].last_name());
		print_formatted_str(_contact_list[i].nickname());
		std::cout << "|" << std::endl;
	}

	std::cout << "Please enter the index of the contact you want to see." << std::endl;
	std::cin.clear();
	std::cin >> index;
	if (std::cin.fail() index < 1 || index > _nb_contacts) {
		std::cout << "please enter an existing index" << std::endl;
		std::cin.clear();
		std::cin.ignore(10000,'\n');
		return;
	}
	std::cin.clear();
	std::cin.ignore(10000,'\n');

	std::cout << "First name : " << _contact_list[index - 1].first_name() << std::endl;
	std::cout << "Last name : " << _contact_list[index - 1].last_name() << std::endl;
	std::cout << "Nickname : " << _contact_list[index - 1].nickname() << std::endl;
	std::cout << "Phone number : " << _contact_list[index - 1].phone_number() << std::endl;
	std::cout << "Darkest secret : " << _contact_list[index - 1].darkest_secret() << std::endl;
}
