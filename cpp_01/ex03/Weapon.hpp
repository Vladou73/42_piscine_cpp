#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
    public :
        Weapon(std::string);
        ~Weapon(void);

        const std::string   &getType(void) const;
        void                setType(std::string const &);

    private :
        std::string _type;
};

#endif