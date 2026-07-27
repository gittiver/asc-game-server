#include <filesystem>
#include <string>

#include "asc_server.hpp"

#include <crow/json.h>

server::server(const std::string& basedir)
{
  settings.basedir = basedir;
  games.push_back({1,
                   {{1, "frank", "frank.landgraf@web.de"},
                    {2, "gulliver1", "gulliver@traumkristalle.net"}},
                   {},
                   {}});
}

auto server::get_map(unsigned int map_id) -> map*
{
  for (auto& map : maps) {
    if (map.id == map_id) {
      return &map;
    }
  }

  return nullptr;
}

auto server::get_mapfile(unsigned int map_id) -> std::string
{
  map const* pmap = get_map(map_id);
  if (nullptr == pmap) {
    return {};
  } else {
    return /*settings.map_basedir + "/" + */ pmap->file_name;
  }
}

auto server::load() -> bool
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
    auto maps = basedir / "maps";
    if (!is_directory(maps)) {
      success = false;
    } else {
      unsigned int map_id = 1;
      for (const auto& entry : std::filesystem::directory_iterator(maps)) {
        if (entry.is_regular_file()) {
          map const map_entry {.id = map_id,
                               .name = entry.path().stem(),
                               .file_name = entry.path().filename()};
          this->maps.push_back(map_entry);
          map_id++;
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
  auto basedir = settings.basedir.empty()
      ? std::filesystem::current_path()
      : std::filesystem::path(settings.basedir);

  return success;
}
