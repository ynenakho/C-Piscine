#include "ScavTrap.hpp"

void ScavTrap::challengeNewcomer(std::string const & target) {
  if (this->energyPoints < 25) {
    std::cout << "Claptrap " << this->name << " doesnt have enougth energy." << std::endl;
    return;
  }

  this->energyPoints -= 25;
  std::string attackArray[5] = {
    " Dance",
    " Trip",
    " Fall down",
    " Shoot himself",
    " Cook a cake"
  };
  std::cout << "Claptrap " << this->name << " made " << target
            << attackArray[rand() % 5]
            << "!" << std::endl;

}

void ScavTrap::beRepaired(unsigned int amount) {
  if (this->hitPoints == this->maxHitPoints) {
    std::cout << "Claptrap " << this->name << " has maximum hitPoints and cant be repaired." << std::endl;
    return ;
  }
  this->hitPoints = ((this->hitPoints + (int)amount) < this->maxHitPoints) ?
                          this->hitPoints + amount : this->maxHitPoints;
  std::cout << "Claptrap " << this->name << " was Repaired. Now he have "
                        << this->hitPoints << " left." << std::endl;
  return;
}


void ScavTrap::rangedAttack(std::string const & target) {
  if (this->energyPoints < 25) {
    std::cout << "Claptrap " << this->name << " doesnt have enougth energy. "
              << this->energyPoints << " points left." << std::endl;
    return ;
  }
  this->energyPoints -= 25;
  std::cout << "Claptrap " << this->name << " attacks " << target
            << " at range, causing " << this->rangedAttackDmg
            << " points of damage!" << std::endl;
  return ;
}

void ScavTrap::meleeAttack(std::string const & target) {
  if (this->energyPoints < 25) {
    std::cout << this->name << " doesnt have enougth energy. "
              << this->energyPoints << " points left." << std::endl;
    return ;
  }
  this->energyPoints -= 25;
  std::cout << "Claptrap " << this->name << " attacks " << target
            << " in melee, causing " << this->meleeAttackDmg
            << " points of damage!" << std::endl;
  return ;
}

void ScavTrap::takeDamage(unsigned int amount) {
  if ((int)amount < this->hitPoints) {
    this->hitPoints -= amount - this->armorDmgReduction;
    std::cout << "Claptrap " << this->name << " was damaged on "
    << amount - this->armorDmgReduction << " of hit points. Now he have " << this->hitPoints
    << " left." << std::endl;
  }
  else {
    this->hitPoints = 0;
    std::cout << "Claptrap " << this->name << " was killed." << std::endl;
  }
  return;
}

ScavTrap::~ScavTrap() {
  std::cout << "Claptrap named " << this->name << " destructed." << std::endl;
  return;
}

ScavTrap::ScavTrap(std::string name) : name(name) {
      srand(time(NULL));
  this->hitPoints = 100;
  this->maxHitPoints = 100;
  this->energyPoints = 50;
  this->maxEnergyPoints = 50;
  this->level = 1;
  this->meleeAttackDmg = 20;
  this->rangedAttackDmg = 13;
  this->armorDmgReduction = 3;
  std::cout << "Claptrap named " << this->name << " created." << std::endl;
  return;
}
