cmake_minimum_required(VERSION 3.23.2)
project(gallows C)

set(CMAKE_C_STANDARD 11)

add_executable(gallows
        main.c word_base.c word_base.h)
