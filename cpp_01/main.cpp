/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:00:14 by vnafissi          #+#    #+#             */
/*   Updated: 2022/12/21 17:52:52 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

int main(void) {
	std::cout << "Creation z_1 avec allocation dynamique" << std::endl;
	Zombie* z_1= newZombie("zomb_1");
	std::cout << "appel methode announce dans le main" << std::endl;
	Zombie->announce();

	std::cout << "Creation z_2 sans allocation dynamique" << std::endl;
	randomChump("zomb_2");


	return 0;

}
