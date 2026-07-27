#include <string>

#include "asc_server.hpp"
#include "crow/app.h"
#include "json_encoding.hpp"

auto main(int /*argc*/, char* /*argv*/[]) -> int
{
  server server("");
  server.load();

  crow::App<> app;

  CROW_ROUTE(app, "/user")
      .methods(crow::HTTPMethod::Get)(
          []() -> crow::response
          { return {crow::status::NOT_IMPLEMENTED, "user"}; });

  CROW_ROUTE(app, "/user")
      .methods(crow::HTTPMethod::Post)(
          []() -> crow::response
          { return {crow::status::NOT_IMPLEMENTED, "user"}; });

  CROW_ROUTE(app, "/user/<uint>")
      .methods(crow::HTTPMethod::Get)(
          [](uint64_t user_id) -> crow::response
          { return {crow::status::NOT_IMPLEMENTED, std::to_string(user_id)}; });

  CROW_ROUTE(app, "/user/<uint>/games")
      .methods(crow::HTTPMethod::Get)(
          [](uint64_t game_id) -> crow::response
          { return {crow::status::NOT_IMPLEMENTED, std::to_string(game_id)}; });

  CROW_ROUTE(app, "/games/")
      .methods(crow::HTTPMethod::Get)(
          [](const crow::request& request) -> crow::response
          { return {crow::status::NOT_IMPLEMENTED, request.url}; });

  CROW_ROUTE(app, "/games/")
      .methods(crow::HTTPMethod::Post)(
          [](const crow::request& request) -> crow::response
          { return {crow::status::NOT_IMPLEMENTED, request.url}; });
  CROW_ROUTE(app, "/games/<uint>")
      .methods(crow::HTTPMethod::Get)(
          [](const crow::request& request,
             unsigned int game_id) -> crow::response
          {
            return {crow::status::NOT_IMPLEMENTED,
                    request.url + " " + std::to_string(game_id)};
          });
  CROW_ROUTE(app, "/games/<uint>")
      .methods(crow::HTTPMethod::Post)(
          [](const crow::request& request,
             unsigned int game_id) -> crow::response
          {
            return {crow::status::NOT_IMPLEMENTED,
                    request.url + " " + std::to_string(game_id)};
          });
  CROW_ROUTE(app, "/admin/games")
      .methods(crow::HTTPMethod::Post, crow::HTTPMethod::Get)(
          [](const crow::request& request) -> crow::response
          { return {crow::status::NOT_IMPLEMENTED, request.url}; });

  CROW_ROUTE(app, "/admin/games/<uint>")
      .methods(crow::HTTPMethod::Post, crow::HTTPMethod::Get)(
          [](const crow::request& request,
             unsigned int game_id) -> crow::response
          {
            return {crow::status::NOT_IMPLEMENTED,
                    request.url + " " + std::to_string(game_id)};
          });

  CROW_ROUTE(app, "/maps")
      .methods(crow::HTTPMethod::Get)(
          [&server]() -> crow::response
          {
            crow::json::wvalue ret = list_to_json(server.maps);
            return ret;
          });

  CROW_ROUTE(app, "/maps/<uint>")
      .methods(crow::HTTPMethod::Get)(
          [&server](unsigned int map_id) -> crow::response
          {
            auto* map = server.get_map(map_id);
            if (!map) {
              return {crow::status::NOT_FOUND,
                      error_response(0, "id not found")};
            }
            return to_json(*map);
          });

  CROW_ROUTE(app, "/maps/<uint>/gamemap")
      .methods(crow::HTTPMethod::Get)(
          [&server](unsigned int map_id) -> crow::response
          {
            auto* map = server.get_map(map_id);
            if (!map) {
              return {crow::status::NOT_FOUND,
                      error_response(0, "id not found")};
            }
            const std::string fname = server.get_mapfile(map_id);
            crow::response res;
            res.set_static_file_info(fname, "application/octet-stream");
            res.set_header("Content-Disposition",
                           "attachment; filename=\"gamemap.asc\"");
            return res;
          });

  CROW_ROUTE(app, "/maps/<uint>")
      .methods(crow::HTTPMethod::Post)(
          [](const crow::request& request,
             unsigned int map_id) -> crow::response
          {
            return {crow::status::NOT_IMPLEMENTED,
                    "post " + request.url + " " + std::to_string(map_id)};
          });

  app.port(18080).run();

  return 0;
}
