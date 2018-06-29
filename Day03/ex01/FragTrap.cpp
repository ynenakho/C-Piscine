#include "FragTrap.hpp"

void FragTrap::vaulthunter_dot_exe(std::string const & target) {
  if (this->energyPoints < 25) {
    std::cout << "FR4G-TP " << this->name << " doesnt have enougth energy." << std::endl;
    return;
  }

  this->energyPoints -= 25;
  std::string attackArray[5] = {
    "Hammer",
    "Gun",
    "Shovel",
    "Fork",
    "Rock"
  };
  std::cout << "FR4G-TP " << this->name << " attacks " << target
            << " with " << attackArray[rand() % 5]
            << "!" << std::endl;

}

void FragTrap::beRepaired(unsigned int amount) {
  if (this->hitPoints == this->maxHitPoints) {
    std::cout << "FR4G-TP " << this->name << " has maximum hitPoints and cant be repaired." << std::endl;
    return ;
  }
  this->hitPoints = ((this->hitPoints + (int)amount) < this->maxHitPoints) ?
                          this->hitPoints + amount : this->maxHitPoints;
  std::cout << "FR4G-TP " << this->name << " was Repaired. Now he have "
                        << this->hitPoints << " left." << std::endl;
  return;
}


void FragTrap::rangedAttack(std::string const & target) {
  if (this->energyPoints < 25) {
    std::cout << "FR4G-TP " << this->name << " doesnt have enougth energy. "
              << this->energyPoints << " points left." << std::endl;
    return ;
  }
  this->energyPoints -= 25;
  std::cout << "FR4G-TP " << this->name << " attacks " << target
            << " at range, causing " << this->rangedAttackDmg
            << " points of damage!" << std::endl;
  return ;
}

void FragTrap::meleeAttack(std::string const & target) {
  if (this->energyPoints < 25) {
    std::cout << this->name << " doesnt have enougth energy. "
              << this->energyPoints << " points left." << std::endl;
    return ;
  }
  this->energyPoints -= 25;
  std::cout << "FR4G-TP " << this->name << " attacks " << target
            << " in melee, causing " << this->meleeAttackDmg
            << " points of damage!" << std::endl;
  return ;
}

void FragTrap::takeDamage(unsigned int amount) {
  if ((int)amount < this->hitPoints) {
    this->hitPoints -= amount - this->armorDmgReduction;
    std::cout << "FR4G-TP " << this->name << " was damaged on "
    << amount - this->armorDmgReduction << " of hit points. Now he have " << this->hitPoints
    << " left." << std::endl;
  }
  else {
    this->hitPoints = 0;
    std::cout << "FR4G-TP " << this->name << " was killed." << std::endl;
  }
  return;
}

FragTrap::~FragTrap() {
  std::cout << "FR4G-TP named " << this->name << " destructed." << std::endl;
  return;
}

FragTrap::FragTrap(std::string name) : name(name) {
  srand(time(NULL));
  this->type = "FR4G-TP ";
  this->hitPoints = 100;
  this->maxHitPoints = 100;
  this->energyPoints = 100;
  this->maxEnergyPoints = 100;
  this->level = 1;
  this->meleeAttackDmg = 30;
  this->rangedAttackDmg = 20;
  this->armorDmgReduction = 5;
  std::cout << "FR4G-TP named " << this->name << " created." << std::endl;
  return;
}

FragTrap::FragTrap(FragTrap const &src) {
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
  return;
}

FragTrap &FragTrap::operator= (const FragTrap &obj)
{
  this->name = obj.name;
  this->type = obj.type;
  this->hitPoints = obj.hitPoints;
  this->maxHitPoints = obj.maxHitPoints;
  this->energyPoints = obj.energyPoints;
  this->maxEnergyPoints = obj.maxEnergyPoints;
  this->level = obj.level;
  this->meleeAttackDmg = obj.meleeAttackDmg;
  this->rangedAttackDmg = obj.rangedAttackDmg;
  this->armorDmgReduction = obj.armorDmgReduction;
	return (*this);
}

void FragTrap::stats() {
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
