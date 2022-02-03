cmake_minimum_required(VERSION 3.19)
project(stprpg C)

set(CMAKE_C_STANDARD 99)

# Specify external includes here
include_directories($ENV{DEVKITARM}/include/)
include_directories($ENV{DEVKITPRO}/libgba/include/)
include_directories($ENV{DEVKITPRO}/libtonc/include/)
include_directories($ENV{DEVKITARM}/arm-none-eabi/include)
include_directories(include gfx maps)

add_executable(stprpg source/main.c source/map.c source/state.c source/camera.c source/map_town.c include/map_town.h)