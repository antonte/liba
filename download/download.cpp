#include "download.hpp"
#include <curl/curl.h>
#include <stdexcept>
#include <memory>
#include <sstream>

class CurlGlobal
{
public:
  CurlGlobal()
  {
    CURLcode code = curl_global_init(CURL_GLOBAL_ALL);
    if (code)
    {
      throw std::runtime_error("Unable to curl_global_init");
    }
  }
  ~CurlGlobal()
  {
    curl_global_cleanup();
  }
  static void init()
  {
    static CurlGlobal curlGlobal;
  }
public:
};

static size_t curlWrite(void *buffer, size_t size, size_t nmemb, void *userp)
{
  ((std::ostringstream *)userp)->write((char *)buffer, size * nmemb);
  return size * nmemb;
}


std::string download(const std::string &url)
{
  CurlGlobal::init();
  std::ostringstream strm;
  std::unique_ptr<CURL, decltype(&curl_easy_cleanup)> tmp(curl_easy_init(), curl_easy_cleanup);
  if (!tmp)
    throw std::runtime_error("Failed to init");
  auto handle = tmp.get();
  curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, curlWrite);
  curl_easy_setopt(handle, CURLOPT_WRITEDATA, &strm);
  curl_easy_setopt(handle, CURLOPT_URL, url.c_str());
  long noSignal = 1;
  curl_easy_setopt(handle, CURLOPT_NOSIGNAL, noSignal);
  CURLcode code = curl_easy_perform(handle);
  strm.flush();
  if (code != CURLE_OK)
  {
    std::ostringstream strm;
    strm << "Could not download '" << url << "'. CURL finished with error " << code << ": " << curl_easy_strerror(code);
    throw std::runtime_error(strm.str());
  }
  return strm.str();
}
