/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:00:14 by vnafissi          #+#    #+#             */
/*   Updated: 2022/12/19 18:34:17 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"
#include "Phonebook.hpp"


int main(void) {
	std::string action;
	std::string input;
	Phonebook	phonebook;

	std::cout << "Choose between 'ADD', 'SEARCH' or 'EXIT'" << std::endl;
	std::getline(std::cin, action);
	if (action.compare("ADD") == 0) {
		std::cin.clear();
		phonebook.add_contact();


	std::cout	<< "last name of 1st contact is : "
				<< phonebook.contact_list[0].last_name();
				<< std::endl;


	} else if (action.compare("SEARCH") == 0) {
		std::cout << "ACTION SEARCH" << std::endl;
	} else if (action.compare("EXIT") == 0) {
		std::cout << "ACTION EXIT" << std::endl;
		return (0);
	}
	return 0;
}
