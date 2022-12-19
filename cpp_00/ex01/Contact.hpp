/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:25:10 by vnafissi          #+#    #+#             */
/*   Updated: 2022/12/19 16:14:16 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

class Contact {

public:
	Contact(void);
	~Contact(void);

	//getters
	std::string	first_name(void) const;
	std::string	last_name(void) const;
	std::string	nickname(void) const;
	std::string	phone_number(void) const;

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
