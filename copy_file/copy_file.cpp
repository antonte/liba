#include "copy_file.hpp"
#include <fstream>
#include <stdexcept>

void copyFile(std::string fromFileName, std::string toFileName)
{
  std::ifstream from(fromFileName, std::ios::binary);
  if (!from.good())
    throw std::runtime_error("Could not open the file: " + fromFileName);
  std::ofstream to(toFileName, std::ios::binary);
  if (!to.good())
    throw std::runtime_error("Could not open the file: " + toFileName);
  to << from.rdbuf();
}
