//https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7531561-decouvrez-la-notion-dheritage

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    public:
        FragTrap(std::string const &);
        FragTrap(FragTrap const &);
        ~FragTrap(void);
        FragTrap & operator=(FragTrap const &);

        void highFivesGuys(void);
    
    private:
        FragTrap(void);
};

#endif