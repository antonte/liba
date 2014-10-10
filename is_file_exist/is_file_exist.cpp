#include "is_file_exist.hpp"
#include <fstream>

bool isFileExist(const std::string &fileName) noexcept
{
  return std::ifstream(fileName).good();
}
