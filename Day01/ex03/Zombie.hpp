#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie {
private:
  std::string zName;
  std::string zType;

public:
  Zombie();
  ~Zombie();

  void announce();
};

#endif
