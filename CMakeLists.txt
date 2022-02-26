cmake_minimum_required(VERSION 3.19)
project(stprpg C)

set(CMAKE_C_STANDARD 99)

# Specify external includes here
include_directories($ENV{DEVKITARM}/include/)
include_directories($ENV{DEVKITPRO}/libgba/include/)
include_directories($ENV{DEVKITPRO}/libtonc/include/)
include_directories($ENV{DEVKITARM}/arm-none-eabi/include)
include_directories(include gfx maps include/character_states)

add_executable(stprpg
        source/main.c
        source/map.c
        source/state.c
        source/camera.c
        source/map_town.c
        include/map_town.h
        source/sprite.c
        include/sprite.h
        source/character.c
        include/character.h
        source/character_states/move_state.c
        source/character_states/wait_state.c
        source/character_states/states.c
        include/character_states/states.h
        source/actions.c
        include/actions.h
        source/trigger.c
        include/trigger.h
        include/game.c
        include/game.h
        maps/map1.c
        maps/map1_data.c)
