#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"

int main() {
  NinjaTrap rob1("Vasya");
  FragTrap rob2("Nik");
  ScavTrap rob3("Gosha");

  rob1.ninjaShoebox(rob1);
  rob1.ninjaShoebox(rob2);
  rob1.ninjaShoebox(rob3);
  return 0;
}
