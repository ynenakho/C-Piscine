#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
  if (argc != 4)
  {
    std::cout << "Usage: ./replace [filename] [string] [string].";
    return -1;
  }
  char filename[512];
  std::ifstream fileToRead(argv[1]);
  if (!fileToRead)
  {
      std::cerr << "Could not open " << argv[1] << "\n";
      return -1;
  }
  strcpy(filename, argv[1]);
  strcat(filename, ".replace");
  std::ofstream fileToWright(filename);
  if (!fileToWright)
  {
      std::cerr << "Could not open " << filename << "\n";
      return -1;
  }
  std::string stringToReplace(argv[2]);
  std::string stringToReplaceWith(argv[3]);
  std::string line;
  size_t index = 0;
  while (getline(fileToRead, line))
  {
    while ((index = line.find(stringToReplace)) != std::string::npos)
      line.replace(index, stringToReplace.length(), stringToReplaceWith);
    fileToWright << line << std::endl;
  }
  return 0;
}
