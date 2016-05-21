#include "hugopeixoto/uri/uri.h"
#include <regex>
#include <stdlib.h>

Optional<uri::URI> uri::parse(const std::string& uristring) {
  URI result;

  std::regex re("(.+)://((.+):(.+)@)?([^:]+)(:(\\d+))?(/[^?]*)(\\?(.*))?");

  std::smatch matches;

  if (!std::regex_search(uristring, matches, re)) {
    return Optional<uri::URI>();
  }

  result.scheme = matches.str(1);

  if (matches[2].matched) {
    result.username = matches.str(3);
    result.password = matches.str(4);
  }

  result.hostname = matches.str(5);

  if (matches[7].matched) {
    result.port = strtol(matches.str(7).c_str(), nullptr, 10);
  }

  result.path = matches.str(8);

  if (matches[10].matched) {
    result.query = matches.str(10);
  }

  return result;
}
