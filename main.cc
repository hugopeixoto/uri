#include "hugopeixoto/uri/uri.h"
#include <iostream>

int main(int argc, char *argv[]) {
  auto uris = {
    std::string("postgresql://hpeixoto:qwerty@localhost:5432/store?pool=5"),
    std::string("https://localhost/"),
  };

  for (auto uri : uris) {
    auto u = uri::parse(uri).unwrap();

    std::cout << "parsing " << uri << std::endl;
    std::cout << u.scheme << std::endl;
    std::cout << u.username.orDefault("<none>") << std::endl;
    std::cout << u.password.orDefault("<none>") << std::endl;
    std::cout << u.hostname << std::endl;
    std::cout << u.port.orDefault(0) << std::endl;
    std::cout << u.path.orDefault("<none>") << std::endl;
    std::cout << u.query.orDefault("<none>") << std::endl;
    std::cout << "-----" << std::endl;
  }

  return 0;
}
