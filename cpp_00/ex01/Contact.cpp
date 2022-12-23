#include <iostream>
#include "Contact.hpp"

Contact::Contact(void) {
	// std::cout << "appel du constructeur Contact" << std::endl;
	return;
}
Contact::~Contact(void) {
	// std::cout << "appel du destructeur Contact" << std::endl;
	return;
}

//********** GETTERS **********//
std::string	Contact::first_name(void) const {
	return _first_name;
}

string	Contact::last_name(void) const {
	return _last_name;
}

string	Contact::nickname(void) const {
	return _nickname;
}

string	Contact::phone_number(void) const {
	return _phone_number;
}

string	Contact::darkest_secret(void) const {
	return _darkest_secret;
}

//********** SETTERS **********//
void	Contact::first_name(std::string first_name) {
	_first_name.assign(first_name);
}

void	Contact::last_name(std::string last_name) {
	_last_name.assign(last_name);
}

void	Contact::nickname(std::string nickname) {
	_nickname.assign(nickname);
}

void	Contact::phone_number(std::string phone_number) {
	_phone_number.assign(phone_number);
}

void	Contact::darkest_secret(std::string darkest_secret) {
	_darkest_secret.assign(darkest_secret);
}
