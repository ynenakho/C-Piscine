#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
  FragTrap warrior1("Vasya");
  ScavTrap warrior2("Greg");
  warrior1.meleeAttack("Alex");
  warrior1.rangedAttack("Alex");
  warrior1.takeDamage(50);
  warrior1.takeDamage(25);
  warrior1.takeDamage(50);
  warrior1.beRepaired(50);
  warrior1.beRepaired(50);
  warrior1.beRepaired(50);
  warrior1.vaulthunter_dot_exe("Max");
  warrior1.vaulthunter_dot_exe("Max");
  warrior1.vaulthunter_dot_exe("Max");
  warrior2.rangedAttack("Dug");
  warrior2.meleeAttack("Dug");
  warrior2.takeDamage(50);
  warrior2.takeDamage(25);
  warrior2.takeDamage(50);
  warrior2.beRepaired(50);
  warrior2.beRepaired(50);
  warrior2.beRepaired(50);
  warrior2.challengeNewcomer("Gremlin");
  warrior2.challengeNewcomer("Gremlin");
  warrior2.challengeNewcomer("Gremlin");
  ScavTrap warrior3("Anton");
  warrior3.challengeNewcomer("Gremlin");
  warrior3.challengeNewcomer("Gremlin");
  return 0;
}
