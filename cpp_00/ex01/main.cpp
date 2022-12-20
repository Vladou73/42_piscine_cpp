/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:00:14 by vnafissi          #+#    #+#             */
/*   Updated: 2022/12/20 16:09:47 by vnafissi         ###   ########.fr       */
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

	while (1) {
		std::cout << "Choose between 'ADD', 'SEARCH' or 'EXIT'" << std::endl;
		std::cin.clear();
		std::getline(std::cin, action);
		if (std::cin.eof() || action.compare("EXIT") == 0)
			return (0);
		std::cin.clear();
		if (action.compare("ADD") == 0)
			phonebook.add_contact();
		else if (action.compare("SEARCH") == 0)
			phonebook.search_contact();
	}
	return 0;

}
