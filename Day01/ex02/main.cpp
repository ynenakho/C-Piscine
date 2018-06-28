#include "ZombieEvent.hpp"
#include "Zombie.hpp"

int main()
{
  ZombieEvent event;
  event.setZombieType("beast");
  Zombie *zomb1 = event.newZombie("Vasya");
  event.randomChump();
  zomb1->announce();
  delete zomb1;
  return 0;
}
