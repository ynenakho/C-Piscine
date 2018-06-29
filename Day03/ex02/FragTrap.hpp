#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
  FragTrap(std::string name = "Default");
  ~FragTrap();
  FragTrap(FragTrap const &src);
  void vaulthunter_dot_exe(std::string const & target);
};

#endif
