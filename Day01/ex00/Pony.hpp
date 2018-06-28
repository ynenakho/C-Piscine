#ifndef PONY_HPP
# define PONY_HPP
# include <iostream>

class Pony {
private:
  std::string ponyName;
public:
  Pony(std::string name);
  ~Pony();

  void makeSound();
};

#endif
