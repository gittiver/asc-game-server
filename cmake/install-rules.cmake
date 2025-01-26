install(
    TARGETS asc-game-server_exe
    RUNTIME COMPONENT asc-game-server_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
