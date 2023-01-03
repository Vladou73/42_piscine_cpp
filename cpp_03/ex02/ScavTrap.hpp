//https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7531561-decouvrez-la-notion-dheritage

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap(std::string const &);
        ScavTrap(ScavTrap const &);
        ~ScavTrap(void);
        ScavTrap & operator=(ScavTrap const &);

        void guardGate(void);
    
    private:
        ScavTrap(void);

};

#endif