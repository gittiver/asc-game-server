# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

project(asc-game-serverTests LANGUAGES CXX)

# ---- Tests ----

add_executable(asc-game-server_test source/asc-game-server_test.cpp)
target_link_libraries(asc-game-server_test PRIVATE asc-game-server_lib)
target_compile_features(asc-game-server_test PRIVATE cxx_std_20)

add_test(NAME asc-game-server_test COMMAND asc-game-server_test)

# ---- End-of-file commands ----

add_folders(Test)
