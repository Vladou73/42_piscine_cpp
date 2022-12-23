#ifndef ZOMBIE_H
# define ZOMBIE_H

class Zombie {

public:
	Zombie(void); //constructor
	Zombie(std::string name); //constructor bis
	~Zombie(void); //destructor

	void name(std::string name); //setter
	void announce(void);

private:
	std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
