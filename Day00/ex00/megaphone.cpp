#include <iostream>

char *strToUpper(char *str)
{
  int i = 0;

  while (str[i])
  {
      str[i] = toupper(str[i]);
      i++;
  }
  return str;
}

int main(int argc, char **argv)
{
  int i = 1;

  if (argc < 2)
  {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
  }
  while (argv[i])
  {
    std::cout << strToUpper(argv[i]);
    i++;
  }
  std::cout << std::endl;
  return 0;
}
