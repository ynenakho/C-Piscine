#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int main() {
  NinjaTrap rob1("Vasya");
  SuperTrap rob3("Gosha");
  rob3.stats();
  rob3.NinjaTrap::ninjaShoebox(rob1);
  rob3.FragTrap::vaulthunter_dot_exe("Zombie");
  rob3.meleeAttack("Dodik");
  rob3.rangedAttack("Dodik");

  rob3.stats();
  return 0;
}
