#ifndef HUMAN_HPP
# define HUMAN_HPP
# include <iostream>
# include "Brain.hpp"

class Human {
private:
    const Brain myBrain;

public:
  Human();
  ~Human();
  const Brain &getBrain();
  std::string identify();
};

#endif
