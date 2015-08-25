#include "hugopeixoto/uri/uri.h"
#include <regex>
#include <stdlib.h>

uri::URI uri::parse(const std::string& uristring) {
  URI result;

  std::regex re("(.+)://((.+):(.+)@)?([^:]+)(:(\\d+))?/([^?]*)(\\?(.*))?");

  std::smatch matches;

  if (!std::regex_search(uristring, matches, re)) {
    return result;
  }

  result.scheme = matches.str(1);
  result.username = matches.str(3);
  result.password = matches.str(4);
  result.hostname = matches.str(5);
  result.port = strtol(matches.str(7).c_str(), nullptr, 10);
  result.path = matches.str(8);

  return result;
}
