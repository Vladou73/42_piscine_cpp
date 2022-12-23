/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladimir <vladimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:00:14 by vnafissi          #+#    #+#             */
/*   Updated: 2022/12/23 17:52:50 by vladimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

int main(void) {
	int	N = 4;
	
	std::cout << "Creation d'une horde de zombies avec allocation dynamique" << std::endl;
	Zombie* zombie_horde = zombieHorde(N, "Zozo le zombie");
	
	for (int i = 0; i < N ; i++) {
		std::cout << "zombie n° " << i + 1 << std::endl;
		zombie_horde[i].announce();
	}
	
	std::cout << "delete la horde de zombies pour libérer la mémoire allouée" << std::endl;
	delete [] zombie_horde;
	
	return 0;
}
