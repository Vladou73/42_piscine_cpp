#ifndef ZOMBIE_H
# define ZOMBIE_H

class Zombie {

public:
	Zombie(std::string name); //constructor
	~Zombie(void); //destructor

	void announce(void);

private:
	std::string _name;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
