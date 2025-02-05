#include <iostream>
#include <string>
#include "crow/app.h"
#include "crow/middleware.h"


#include "lib.hpp"

auto main() -> int
{
  auto const lib = library {};
  auto const message = "Hello from " + lib.name + "!";
  std::cout << message << '\n';

  crow::App<> app;

  CROW_ROUTE(app, "/hello")
        .methods(crow::HTTPMethod::Post, crow::HTTPMethod::Get)
            ([]() {

              CROW_LOG_INFO << "hello";
              return crow::response(crow::status::OK,"hello");
            });


  app.port(18080).run();

  return 0;
}
