#include "Pony.hpp"

void ponyOnTheHeap()
{
  Pony *pony2 = new Pony("Galya");
  pony2->makeSound();
  delete pony2; //free pony2
}

void ponyOnTheStack()
{
  Pony pony1 = Pony("Vasya");
  pony1.makeSound();
}

int main()
{
  ponyOnTheStack();
  ponyOnTheHeap();
  return(0); //free pony1
}
