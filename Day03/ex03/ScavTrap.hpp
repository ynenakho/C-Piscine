#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
  ScavTrap(std::string name = "Default");
  ~ScavTrap();
  ScavTrap(ScavTrap const &src);
  void challengeNewcomer(std::string const & target);
};

#endif
