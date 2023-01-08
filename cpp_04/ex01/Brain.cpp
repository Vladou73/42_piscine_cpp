#include "Brain.hpp"

Brain::Brain(void) {
    std::cout << "Brain constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        if (i % 2)
            this->_ideas[i] = "my_idea_is_beautiful";
        else
            this->_ideas[i] = "my_idea_is_awkward";
    }
    return;
}

Brain::Brain(Brain const& toCopy) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = toCopy;
    return;
}

Brain Brain::operator=(Brain const& toCopy) {
    if (this == &toCopy)
        return *this;
    for (int i=0; i < 100; i++) {
        this->_ideas[i] = toCopy._ideas[i]; 
    }
    return (*this);
}

Brain::~Brain(void) {
    std::cout << "Brain destructor called" << std::endl;
    return;
}

std::string Brain::getIdea(int number) const {
    if (number < 0)
        return this->_ideas[0];
    if (number > 99)
        return this->_ideas[99];
    return this->_ideas[number];
}

void    Brain::setIdea(int number, std::string idea) {
    if (number < 0)
        this->_ideas[0] = idea;
    if (number > 99)
        this->_ideas[99] = idea;
    this->_ideas[number] = idea;
}