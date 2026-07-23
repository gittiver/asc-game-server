#pragma once

#include <memory>
#include <string>
#include <vector>
#include <cstdint>

/**
 * @brief ASC game domain definitions and server
 *
 */

struct player
{
  uint32_t id;
  std::string name;
  std::string email;
};

struct map
{
  uint32_t id;
  std::string name;
  std::string file_name;
};

struct game
{
  uint32_t id;
  std::vector<player> players;
  std::shared_ptr<map> map;
  struct map current_map;
};

struct settings {
  std::string map_basedir;
};

struct server {
  explicit server(const std::string& basedir);
  
  std::vector<map> maps;
  std::vector<game> games;
  std::vector<player> users;
  settings settings;
private:
  auto get_map(int map_id) -> map*;
  auto get_mapfile(int map_id) -> std::string;
};
