#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {

{

  FragTrap warrior("Vasya");
  warrior.rangedAttack("Alex");
  warrior.meleeAttack("Alex");
  warrior.rangedAttack("Alex");
  warrior.rangedAttack("Alex");
  warrior.rangedAttack("Alex");
  warrior.rangedAttack("Alex");
  warrior.takeDamage(50);
  warrior.takeDamage(25);
  warrior.takeDamage(50);
  warrior.beRepaired(50);
  warrior.beRepaired(50);
  warrior.beRepaired(50);
  FragTrap warrior1("Killer");
  warrior1.vaulthunter_dot_exe("Max");
  warrior1.vaulthunter_dot_exe("Max");
  warrior1.vaulthunter_dot_exe("Max");
  warrior1.vaulthunter_dot_exe("Max");
  warrior1.vaulthunter_dot_exe("Max");
}
{
  ScavTrap warrior("Anton");
  warrior.stats();
  warrior.rangedAttack("Dug");
  warrior.meleeAttack("Dug");
  warrior.rangedAttack("Dug");
  warrior.rangedAttack("Dug");
  warrior.rangedAttack("Dug");
  warrior.rangedAttack("Dug");
  warrior.stats();
  warrior.takeDamage(50);
  warrior.takeDamage(25);
  warrior.takeDamage(50);
  warrior.stats();
  warrior.beRepaired(50);
  warrior.beRepaired(50);
  warrior.beRepaired(50);
  warrior.stats();
  ScavTrap warrior1("Beast");
  warrior1.stats();
  warrior1.challengeNewcomer("Gremlin");
  warrior1.challengeNewcomer("Gremlin");
  warrior1.challengeNewcomer("Gremlin");
  warrior1.challengeNewcomer("Gremlin");
  warrior1.challengeNewcomer("Gremlin");
  warrior1.stats();
  return 0;
}
}
