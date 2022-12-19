/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:25:10 by vnafissi          #+#    #+#             */
/*   Updated: 2022/12/19 18:17:56 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
#include "Contact.hpp"


class Phonebook {

public:
	Contact contact_list[8];

	Phonebook(void); //constructor
	~Phonebook(void); //destructor

	// int		idx(); //getter
	// void	idx(); //setter

	void	add_contact(void);

	// void	search_contact(contact_list) const;

private:
	int	_idx;
};

#endif
