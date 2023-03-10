/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:25:10 by vnafissi          #+#    #+#             */
/*   Updated: 2022/12/20 15:59:07 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

class Contact {

public:
	Contact(void); //constructor
	~Contact(void); //destructor

	//getters
	std::string	first_name(void) const;
	std::string	last_name(void) const;
	std::string	nickname(void) const;
	std::string	phone_number(void) const;
	std::string	darkest_secret(void) const;

	//setters
	void		first_name(std::string);
	void		last_name(std::string);
	void		nickname(std::string);
	void		phone_number(std::string);
	void		darkest_secret(std::string);

private:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
};

#endif
