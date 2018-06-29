#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class NinjaTrap : public ClapTrap {
public:
  NinjaTrap(std::string name = "Default");
  ~NinjaTrap();
  NinjaTrap(NinjaTrap const &src);
  void ninjaShoebox(NinjaTrap const & obj);
  void ninjaShoebox(ScavTrap const & obj);
  void ninjaShoebox(FragTrap const & obj);
};

#endif
