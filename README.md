liba
====

Micro C++ libraries

Build Instuction
----------------
* use my https://github.com/antonte/build tool
* in the library
$ cd library_nam
* call build a
$ build a

Check if a File Exist
---------------------

```C++
#include <is_file_exist.hpp>

bool isFileExist(const std::string &fileName) noexcept;
```

Copy File
---------

```C++
#include <copy_file.hpp>

void copyFile(const std::string &fromFileName, const std::string &toFileName);
```


TODO
====
* parse a url
* SOAP Library
* How to get file extension from string
* How can I extract the file name and extension from a path
* Get home directory
* Hash function
* Send email
* generate a unique ID
* Rational Number Library
* two dimensional arrays
* Create a new directory
* get the absolute path for a given relative path
* UnixTime to readable date
* Send multiple/single files via HTTP POST
* Extract from  HTML file all links


* Remove duplicates from container without sorting the container

```C++
#include <algorithm>
#include <vector>
struct target_less
{
    template<class It>
    bool operator()(It const &a, It const &b) const { return *a < *b; }
};
struct target_equal
{
    template<class It>
    bool operator()(It const &a, It const &b) const { return *a == *b; }
};
template<class It> It uniquify(It begin, It const end)
{
    std::vector<It> v;
    v.reserve(static_cast<size_t>(std::distance(begin, end)));
    for (It i = begin; i != end; ++i)
    { v.push_back(i); }
    std::sort(v.begin(), v.end(), target_less());
    v.erase(std::unique(v.begin(), v.end(), target_equal()), v.end());
    std::sort(v.begin(), v.end());
    size_t j = 0;
    for (It i = begin; i != end && j != v.size(); ++i)
    {
        if (i == v[j])
        {
            using std::iter_swap; iter_swap(i, begin);
            ++j;
            ++begin;
        }
    }
    return begin;
}
```

* Remove duplicates from container

```C++
sort( vec.begin(), vec.end() );
vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
```

* Load file into string

```C++
std::ifstream t("file.txt");
std::stringstream buffer;
buffer << t.rdbuf();
```

Detecting endianness programmatically
hash function for string

* isExist
* isDir
* isFile

* string low case

```C++
#include <algorithm>
#include <string> 

std::string data = "Abc"; 
std::transform(data.begin(), data.end(), data.begin(), ::tolower);

```

* int to string

* wstring to string

* mktemp

* list of files in a directory

```C++
DIR *dir;
struct dirent *ent;
if ((dir = opendir ("c:\\src\\")) != NULL) {
  /* print all the files and directories within directory */
  while ((ent = readdir (dir)) != NULL) {
    printf ("%s\n", ent->d_name);
  }
  closedir (dir);
} else {
  /* could not open directory */
  perror ("");
  return EXIT_FAILURE;
}
```

http://stackoverflow.com/questions/612097/how-can-i-get-a-list-of-files-in-a-directory-using-c-or-c


* C++ Erase vector element by value rather than by position?

```C++
vec.erase(std::remove(vec.begin(), vec.end(), 8), vec.end());
```
* How to get my ip address in c Linux -…

```C++
getifaddrs(&addrs);
tmp = addrs;

while (tmp) 
{
    if (tmp->ifa_addr && tmp->ifa_addr->sa_family == AF_INET)
    {
        struct sockaddr_in *pAddr = (struct sockaddr_in *)tmp->ifa_addr;
        printf("%s: %s\n", tmp->ifa_name, inet_ntoa(pAddr->sin_addr));
    }

    tmp = tmp->ifa_next;
}

freeifaddrs(addrs);
```

* How do I get the directory that a program is running from?

```C++
#include <stdio.h>  /* defines FILENAME_MAX */
#ifdef WINDOWS
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
 #endif

 char cCurrentPath[FILENAME_MAX];

 if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
     {
     return errno;
     }
     
cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */

printf ("The current working directory is %s", cCurrentPath);
```
Windows:

```C++
int bytes = GetModuleFileName(NULL, pBuf, len);
if(bytes == 0)
	return -1;
else
	return bytes;
```

Linux:

```C++
char szTmp[32];
sprintf(szTmp, "/proc/%d/exe", getpid());
int bytes = MIN(readlink(szTmp, pBuf, len), len - 1);
if(bytes >= 0)
	pBuf[bytes] = '\0';
return bytes;
```

* two-dimensional vectors

* Converting YUV into BGR or RGB

```C++
for(int i = 0, j=0; i < 1280 * 720 * 3; i+=6, j+=4)
{
    m_RGB->imageData[i] = pData[j] + pData[j+3]*((1 - 0.299)/0.615);
    m_RGB->imageData[i+1] = pData[j] - pData[j+1]*((0.114*(1-0.114))/(0.436*0.587)) - pData[j+3]*((0.299*(1 - 0.299))/(0.615*0.587));
    m_RGB->imageData[i+2] = pData[j] + pData[j+1]*((1 - 0.114)/0.436);
    m_RGB->imageData[i+3] = pData[j+2] + pData[j+3]*((1 - 0.299)/0.615);
    m_RGB->imageData[i+4] = pData[j+2] - pData[j+1]*((0.114*(1-0.114))/(0.436*0.587)) - pData[j+3]*((0.299*(1 - 0.299))/(0.615*0.587));
    m_RGB->imageData[i+5] = pData[j+2] + pData[j+1]*((1 - 0.114)/0.436);
}
```

* Convert time_t to string with format YYYY-MM-DD HH:MM:SS

```C++
char buff[20];
time_t now = time(NULL);
strftime(buff, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
```

* How to convert a string variable containing time to time_t type in c++?

```C++
const char *time_details = "16:35:12";
struct tm tm;
strptime(time_details, "%H:%M:%S", &tm);
time_t t = mktime(&tm);  // t is now your desired time_t
```

* Path to binary in C

```C++
#include <stdio.h>
#include <unistd.h>

int main()
{
  char buffer[BUFSIZ];
  readlink("/proc/self/exe", buffer, BUFSIZ);
  printf("%s\n", buffer);
}

WCHAR path[MAX_PATH];
GetModuleFileName(NULL, path, ARRAYSIZE(path));
```
