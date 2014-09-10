#include "read_file.hpp"
#include <sstream>
#include <fstream>

std::string readFile(std::string fileName)
{
  std::ifstream f(fileName);
  std::stringstream strm;
  strm << f.rdbuf();
  return strm.str();
}
