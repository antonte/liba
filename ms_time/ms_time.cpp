#include "ms_time.hpp"
#include <sys/time.h>
#include <cstring>
#include <stdexcept>
#include <sstream>

uint64_t msTime()
{
  struct timeval tv;
  if (gettimeofday(&tv, nullptr) != 0)
  {
    auto errCode = errno;
    std::ostringstream strm;
    strm << "Error: [" << errCode << "] " << strerror(errCode);
    throw std::runtime_error(strm.str());
  }
  return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

