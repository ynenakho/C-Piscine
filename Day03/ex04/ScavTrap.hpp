#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {
public:
  ScavTrap(std::string name = "Default");
  ~ScavTrap();
  ScavTrap(ScavTrap const &src);
  ScavTrap &operator= (const ScavTrap &obj);
  void challengeNewcomer(std::string const & target);
};

#endif
