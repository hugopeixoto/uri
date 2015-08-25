#include "hugopeixoto/uri/uri.h"
#include <iostream>

int main(int argc, char *argv[]) {
  auto pg = uri::parse("postgresql://hpeixoto:qwerty@localhost:5432/store?pool=5");

  std::cout << pg.scheme << std::endl;
  std::cout << pg.port << std::endl;

  return 0;
}
