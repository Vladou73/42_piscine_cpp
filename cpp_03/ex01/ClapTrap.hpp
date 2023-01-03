#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
    public:
        //constructors, destructors
        ClapTrap(std::string const &);          //constructeur avec name
        ClapTrap(std::string const &name, int hit_pts, int energy_pts, int attack_dmg); //constructeur avec plusieurs paramè
        ClapTrap(ClapTrap const &);             //constructeur de recopie
        ~ClapTrap(void);                        //destructeur
        ClapTrap& operator=(ClapTrap const &);  //surcharge de l’opérateur d’affectation

        //member functions
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

    protected:
        ClapTrap(void);                         //constructeur par défaut

        std::string _name;
        int         _hit_pts;
        int         _energy_pts;
        int         _attack_dmg;
};

#endif