#ifndef HUGOPEIXOTO_URI_URI_H_
#define HUGOPEIXOTO_URI_URI_H_

#include <string>

namespace uri {
  struct URI {
    std::string scheme;
    std::string username;
    std::string password;
    std::string hostname;
    std::string path;
    uint16_t port;
  };

  URI parse(const std::string& uristring);
}

#endif
