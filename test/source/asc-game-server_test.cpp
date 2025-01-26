#include "lib.hpp"

auto main() -> int
{
  auto const lib = library {};

  return lib.name == "asc-game-server" ? 0 : 1;
}
