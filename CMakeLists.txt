#--------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.21.3)

set(VCPKG_ROOT "C:/Users/79219/source/repos/vcpkg")
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

project(Journal)

#--------------------------------------------------------------------------------

# Libraries include
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

# Sources include
add_executable(${PROJECT_NAME} evolution.cpp objects/cell.cpp objects/cell.hpp objects/bot.cpp objects/bot.hpp objects/empty.cpp objects/empty.hpp objects/food.cpp objects/food.hpp objects/poison.cpp objects/poison.hpp objects/wall.cpp objects/wall.hpp
world.cpp world.hpp point.cpp point.hpp)
# Libraries include
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-network sfml-graphics sfml-window)

# Output file name settings
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/$<0:>)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX .exe)

#--------------------------------------------------------------------------------
