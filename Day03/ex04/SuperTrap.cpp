#include "SuperTrap.hpp"

SuperTrap::~SuperTrap() {
  std::cout << "SPR0-TP named " << this->name << " destructed." << std::endl;
  return;
}

SuperTrap::SuperTrap(std::string name) {
  srand(time(NULL));
  this->name = name;
  this->type = "SPR0-TP ";
  this->hitPoints = FragTrap::hitPoints;
  this->maxHitPoints = FragTrap::maxHitPoints;
  this->energyPoints = NinjaTrap::energyPoints;
  this->maxEnergyPoints = NinjaTrap::maxEnergyPoints;
  this->level = 1;
  this->meleeAttackDmg = NinjaTrap::meleeAttackDmg;
  this->rangedAttackDmg = FragTrap::rangedAttackDmg;
  this->armorDmgReduction = FragTrap::armorDmgReduction;
  std::cout << "SPR0-TP named " << this->name << " created." << std::endl;
  return;
}

SuperTrap::SuperTrap(SuperTrap const &src) {
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
  return;
}

SuperTrap &SuperTrap::operator= (const SuperTrap &obj)
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

void SuperTrap::meleeAttack(std::string const &target)
{
	return (NinjaTrap::meleeAttack(target));
}

void SuperTrap::rangedAttack(std::string const &target)
{
	return (FragTrap::rangedAttack(target));
}
