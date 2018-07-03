#include "Bureaucrat.hpp"


int
main(void)
{
  try
  {
  //      Bureaucrat bur3("Rob", 0);
    Bureaucrat bur2("Bob", 149);
    std::cout << bur2 << std::endl;
    bur2.incrementGrade();
    std::cout << bur2 << std::endl;
    bur2.decrementGrade();
    std::cout << bur2 << std::endl;
    bur2.decrementGrade();
    std::cout << bur2 << std::endl;
    bur2.decrementGrade();
    std::cout << bur2 << std::endl;
//    Bureaucrat bur3("Rob", 0);
    // Bureaucrat bur("Kob", 156);
    // std::cout << bur << std::endl;
    Bureaucrat bur3("Rob", 0);
    std::cout << bur3 << std::endl;

  }
  catch (std::exception &e)
  {
      std::cout << e.what() << std::endl;
  }
  return (0);
}
