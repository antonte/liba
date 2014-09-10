#include "file_size.hpp"
#include <fstream>
#include <stdexcept>

uint64_t fileSize(std::string fileName)
{
  std::ifstream f(fileName, std::ifstream::ate | std::ifstream::binary);
  if (!f.good())
    throw std::runtime_error("Could not open the file: " + fileName);
  return f.tellg(); 
}
