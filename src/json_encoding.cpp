#include "json_encoding.hpp"

auto error_response(int errorcode, const std::string& errortext)
    -> crow::json::wvalue
{
  return crow::json::wvalue {
      {"type", "error"},
      {"error_code", std::to_string(errorcode)},
      {"error_text", errortext},
  };
}

auto to_json(const map& map) -> crow::json::wvalue
{
  return crow::json::wvalue {
      {"type", "map"},
      {"id", map.id},
      {"name", map.name},
      {"filename", map.file_name},
  };
}

auto to_json(const game& game) -> crow::json::wvalue
{
  return crow::json::wvalue {{"type", "game"},
                             {"id", game.id},
                             {"players", {}},
                             {"map", {}},
                             {"currentmap", {}}};
}
