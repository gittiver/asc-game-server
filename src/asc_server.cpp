#include <string>
#include "asc_server.hpp"

#include <utility>

server::server(const std::string& basedir) {
  settings.map_basedir = basedir;
  map const m {
    .id=1,
    .name="name",
    .file_name = "filename"
  };
  maps.push_back(m);
}

auto server::get_map(int map_id) -> map* {
  for(auto & map: maps) {
    if (map.id == map_id) {
      return &map;
    }
  }

  return nullptr;
}

auto server::get_mapfile(int map_id) -> std::string
{
  map const* pmap = get_map(map_id);
  if (nullptr==pmap) {
    return settings.map_basedir + "/" + pmap->file_name;
  }

  return std::string{};
}
