#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void ClapTrap::stats() {
  std::cout  << "\033[1;32mName: " << this->name << std::endl;
  std::cout << "Type: " << this->type << std::endl;
  std::cout << "Hit Points: " << this->hitPoints << " out of " << this->maxHitPoints << std::endl;
  std::cout << "Energy Points: " << this->energyPoints << " out of " << this->maxEnergyPoints << std::endl;
  std::cout << "Level: " << this->level << std::endl;
  std::cout << "Melee Dmg: " << this->meleeAttackDmg << std::endl;
  std::cout << "Ranged Dmg: " << this->rangedAttackDmg << std::endl;
  std::cout << "Armor Reduction: " << this->armorDmgReduction << "\033[0m" << std::endl;
  return;
}

std::string ClapTrap::getName() const {
  return this->name;
}

std::string ClapTrap::getType() const {
  return this->type;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (this->hitPoints == this->maxHitPoints) {
    std::cout << this->type << this->name << " has maximum hitPoints and cant be repaired." << std::endl;
    return ;
  }
  this->hitPoints = ((this->hitPoints + (int)amount) < this->maxHitPoints) ?
                          this->hitPoints + amount : this->maxHitPoints;
  std::cout << this->type << this->name << " was Repaired. Now he have "
                        << this->hitPoints << " left." << std::endl;
  return;
}


void ClapTrap::rangedAttack(std::string const & target) {
  if (this->energyPoints < 25) {
    std::cout << this->type << this->name << " doesnt have enougth energy. "
              << this->energyPoints << " points left." << std::endl;
    return ;
  }
  this->energyPoints -= 25;
  std::cout << this->type << this->name << " attacks " << target
            << " at range, causing " << this->rangedAttackDmg
            << " points of damage!" << std::endl;
  return ;
}

void ClapTrap::meleeAttack(std::string const & target) {
  if (this->energyPoints < 25) {
    std::cout << this->name << " doesnt have enougth energy. "
              << this->energyPoints << " points left." << std::endl;
    return ;
  }
  this->energyPoints -= 25;
  std::cout << this->type << this->name << " attacks " << target
            << " in melee, causing " << this->meleeAttackDmg
            << " points of damage!" << std::endl;
  return ;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if ((int)amount < this->hitPoints) {
    this->hitPoints -= amount - this->armorDmgReduction;
    std::cout << this->type << this->name << " was damaged on "
    << amount - this->armorDmgReduction << " of hit points. Now he have " << this->hitPoints
    << " left." << std::endl;
  }
  else {
    this->hitPoints = 0;
    std::cout << this->type << this->name << " was killed." << std::endl;
  }
  return;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap class was destructed." << std::endl;
  return;
}

ClapTrap::ClapTrap() {
  std::cout << "ClapTrap class was constructed." << std::endl;
  return;
}


ClapTrap::ClapTrap(ClapTrap const &src) {
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
  return;
}
