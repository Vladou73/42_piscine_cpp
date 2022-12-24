#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>

class HumanA {
    public :
        HumanA(void);
        ~HumanA(void);

        void    attack(void);

    private :
        std::string _name;
        Weapon      _weapon;
};

#endif