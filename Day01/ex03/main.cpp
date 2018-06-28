#include "ZombieHorde.hpp"
#include "Zombie.hpp"

int main()
{
  srand(time(NULL));
  ZombieHorde horde(5);
  horde.announce();
  return 0;
}
