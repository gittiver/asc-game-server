cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    asc-game-server
    VERSION 0.1.0
    DESCRIPTION "a web based game server for the advanced strategic command game"
    HOMEPAGE_URL "asc-server.landgraf.cloud"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    asc-game-server_lib OBJECT
    source/lib.cpp
)

target_include_directories(
    asc-game-server_lib ${warning_guard}
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
)

target_compile_features(asc-game-server_lib PUBLIC cxx_std_20)

# ---- Declare executable ----

add_executable(asc-game-server_exe source/main.cpp)
add_executable(asc-game-server::exe ALIAS asc-game-server_exe)

set_property(TARGET asc-game-server_exe PROPERTY OUTPUT_NAME asc-game-server)

target_compile_features(asc-game-server_exe PRIVATE cxx_std_20)

target_link_libraries(asc-game-server_exe PRIVATE asc-game-server_lib)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT asc-game-server_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of asc-game-server"
  )
endif()

include(cmake/dev-mode.cmake)
