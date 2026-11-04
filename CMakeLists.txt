cmake_minimum_required(VERSION 4.3)
project(gobang_1_1 C)

set(CMAKE_C_STANDARD 99)

add_executable(gobang_1_1
        main.c
        interface.c
        game_administrator.c
        machine/evaluate.c
        machine/linked_list.c
        machine/node_generation.c
        machine/search.c
)
