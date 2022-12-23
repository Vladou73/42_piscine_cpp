/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladimir <vladimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:00:14 by vnafissi          #+#    #+#             */
/*   Updated: 2022/12/23 17:47:55 by vladimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

int main(void) {
	std::cout << "Creation z_1 avec allocation dynamique" << std::endl;
	Zombie* z_1= newZombie("zomb_1");
	std::cout << "appel methode announce dans le main" << std::endl;
	z_1->announce();
	std::cout << "delete manuellement et set le pointer z_1 à NULL pour libérer la mémoire allouée" << std::endl;
	delete z_1;
	z_1 = 0;

	std::cout << "Creation z_2 sans allocation dynamique" << std::endl;
	randomChump("zomb_2");

	return 0;

}
