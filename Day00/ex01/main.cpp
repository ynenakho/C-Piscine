#include "PhoneBook.class.hpp"

int main()
{
  PhoneBook book[8];
  int i = 0;
  char buf[512];
  char ind[10];

  while (true)
  {
    std::cout << "Enter a command: ";
    std::cin >> buf;
    if (!strcmp(buf, "ADD"))
    {
      if (i > 7)
      {
        std::cout << "Phonebook is full" << std::endl;
        continue;
      }
      book[i++].createEntry();
    }
    else if (!strcmp(buf, "SEARCH"))
    {
      std::cout << "\033[1;34m     Index|First name| Last name|  Nickname\033[0m" << std::endl;
      if (i > 0)
      {
        int x = 0;
        while (x < i)
        {
          book[x].displayShort(x + 1);
          x++;
        }
        while (true)
        {
          std::cout << "Enter index: ";
          std::cin >> ind;
          if ((atoi(ind) <= x) && atoi(ind) >= 1)
          {
            book[atoi(ind) - 1].displayAll();
            break ;
          }
          else
            std::cout << "\033[1;31mEnter valid index!!!\033[0m" << std::endl;
        }
      }
    }
    else if (!strcmp(buf, "EXIT"))
      exit(-1);
    else
      std::cout << "\033[1;31mCommands: [ADD, SEARCH, EXIT]\033[0m" << std::endl;
  }
  return 0;
}
