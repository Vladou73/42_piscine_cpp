//Implement a Brain class. It contains an array of 100 std::string called ideas.

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
    public:
        Brain(void);
        Brain(Brain const&);
        Brain operator=(Brain const&);
        ~Brain(void);
        
        std::string getIdea(int number) const;
        void        setIdea(int number, std::string idea);

    private:
        std::string _ideas[100];
};

#endif