#ifndef HUGOPEIXOTO_URI_URI_H_
#define HUGOPEIXOTO_URI_URI_H_

#include "hugopeixoto/optional.h"
#include <string>

namespace uri {
  struct URI {
    std::string scheme;
    Optional<std::string> username;
    Optional<std::string> password;
    std::string hostname;
    Optional<uint16_t> port;
    Optional<std::string> path;
    Optional<std::string> query;
  };

  Optional<URI> parse(const std::string& uristring);
}

#endif
