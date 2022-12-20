/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:25:10 by vnafissi          #+#    #+#             */
/*   Updated: 2022/12/20 15:44:57 by vnafissi         ###   ########.fr       */
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

	void	add_contact(void);
	void	search_contact(void) const;

private:
	int	_idx;
};

#endif
