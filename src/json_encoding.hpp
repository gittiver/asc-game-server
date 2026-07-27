#include "asc_server.hpp"
#include "crow/json.h"

template<class T>
auto list_to_json(const std::vector<T>& array) -> crow::json::wvalue
{
  crow::json::wvalue::list ret;
  for (const auto& item : array) {
    ret.push_back(to_json(item));
  }
  return {ret};
}

auto error_response(int errorcode, const std::string& errortext)
    -> crow::json::wvalue;

auto to_json(const map& map) -> crow::json::wvalue;
auto to_json(const game& game) -> crow::json::wvalue;
