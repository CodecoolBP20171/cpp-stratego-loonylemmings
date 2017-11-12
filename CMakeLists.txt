cmake_minimum_required(VERSION 3.8)
project(cpp_stratego_loonylemmings)

set(CMAKE_CXX_STANDARD 11)

# copied from sdl-example

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

# end of copy


set(SOURCE_FILES main.cpp
        GameObjects/Card.hpp GameObjects/Player.hpp Graphics/UserInput.hpp Graphics/Display.hpp Graphics/GrapicalOutput.cpp Graphics/GrapicalOutput.h GameObjects/Tileset.hpp Graphics/MouseInput.cpp Graphics/MouseInput.h Graphics/DisplayParts.hpp Graphics/CoordinateConverter.hpp)
add_executable(cpp_stratego_loonylemmings ${SOURCE_FILES})

target_link_libraries(cpp_stratego_loonylemmings ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
