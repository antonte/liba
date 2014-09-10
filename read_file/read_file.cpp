#include "read_file.hpp"
#include <sstream>
#include <fstream>
#include <stdexcept>

std::string readFile(std::string fileName)
{
  std::ifstream f(fileName);
  if (!f.good())
    throw std::runtime_error("Could not open the file: " + fileName);
  std::stringstream strm;
  strm << f.rdbuf();
  return strm.str();
}
