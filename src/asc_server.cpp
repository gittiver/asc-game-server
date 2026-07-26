#include <string>
#include <filesystem>

#include "asc_server.hpp"

server::server(const std::string& basedir) {
  settings.basedir = basedir;
}

auto server::get_map(unsigned int map_id) -> map*
{
  for(auto & map: maps) {
    if (map.id == map_id) {
      return &map;
    }
  }

  return nullptr;
}

auto server::get_mapfile(unsigned int map_id) -> std::string
{
  map const* pmap = get_map(map_id);
  if (nullptr==pmap) {
    return {};
  } else {
    return /*settings.map_basedir + "/" + */ pmap->file_name;
  }
}
bool server::load()
{
  bool success = false;
  std::filesystem::path basedir;

  if (settings.basedir.empty()) {
    basedir = std::filesystem::current_path();
  } else {
    basedir = settings.basedir;
  }

  if (!is_directory(basedir)) {
    success = false;
  } else {
    auto maps = basedir/"maps";
    if (!is_directory(maps)) {
      success = false;
    } else {
      unsigned int i=0;
      for (const auto & entry: std::filesystem::directory_iterator(maps)) {
        if (entry.is_regular_file()) {
          map const m{
            .id = i,
            .name = entry.path().stem(),
            .file_name = entry.path().filename()
          };
          this->maps.push_back(m);
          i++;
        }
      }
    }
    success = true;
  }
  return success;
}
auto server::save() -> bool
{
  bool success = false;
  return success;
}
