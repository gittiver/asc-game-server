#include <string>

#include "crow/app.h"
#include "crow/json.h"
//#include "crow/middleware.h"
//#include <auth.hpp>
//#include "bp_user_registration.hpp"


#include "asc_server.hpp"

auto main() -> int
{
  server server(".");
  
  crow::App<> app;

  CROW_ROUTE(app, "/user")
        .methods(crow::HTTPMethod::Get)
            ([]() {
            return crow::response(crow::status::OK,"user");
            });

  CROW_ROUTE(app, "/user")
        .methods(crow::HTTPMethod::Post)
            ([]() {
            return crow::response(crow::status::OK,"user");
            });


  CROW_ROUTE(app, "/user/<uint>")
      .methods(crow::HTTPMethod::Get)
          ([](uint64_t id) {
          return crow::response(crow::status::OK,std::to_string(id));
          });
  CROW_ROUTE(app, "/user/<uint>/games")
        .methods(crow::HTTPMethod::Get)
            ([&server](uint64_t id) {
            return crow::response(crow::status::OK,std::to_string(id));
            });

  CROW_ROUTE(app, "/games/")
        .methods(crow::HTTPMethod::Get)
            ([&server](const crow::request& request) {
	      
	      for (const auto & game : server.games) {
	       
	      }
	      return crow::response(crow::status::OK,request.url);
            });
  CROW_ROUTE(app, "/games/")
        .methods(crow::HTTPMethod::Post)
            ([](const crow::request& request) {
            return crow::response(crow::status::OK,request.url);
            });
  CROW_ROUTE(app, "/games/<uint>")
          .methods(crow::HTTPMethod::Get)
              ([](const crow::request& request, unsigned int id) {
              return crow::response(crow::status::OK,request.url);
              });
  CROW_ROUTE(app, "/games/<uint>")
          .methods(crow::HTTPMethod::Post)
              ([](const crow::request& request, unsigned int id) {
              return crow::response(crow::status::OK,request.url);
              });
  CROW_ROUTE(app, "/admin/games")
            .methods(crow::HTTPMethod::Post, crow::HTTPMethod::Get)
                ([](const crow::request& request) {
                return crow::response(crow::status::OK,request.url);
                });

  CROW_ROUTE(app, "/admin/games/<uint>")
          .methods(crow::HTTPMethod::Post, crow::HTTPMethod::Get)
              ([](const crow::request& request, unsigned int id) {
              return crow::response(crow::status::OK,request.url);
              });

  CROW_ROUTE(app, "/maps")
          .methods(crow::HTTPMethod::Get)
              ([](const crow::request& request) {
		
                    return crow::response(crow::status::OK,request.url);
          
              });
  CROW_ROUTE(app, "/maps/<uint>")
          .methods(crow::HTTPMethod::Get)
              ([](const crow::request& request, unsigned int id) {
                    return crow::response(crow::status::OK,request.url);
          
              });
  CROW_ROUTE(app, "/maps/<uint>")
          .methods(crow::HTTPMethod::Post)
              ([](const crow::request& request, unsigned int id) {
                    return crow::response(crow::status::OK,"post " + request.url);
              });

  app.port(18080).run();

  return 0;
}
