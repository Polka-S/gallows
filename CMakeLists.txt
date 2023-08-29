cmake_minimum_required(VERSION 3.23.2)
project(gallows C)

set(CMAKE_C_STANDARD 11)

add_executable(gallows
        main.c gallows_painter.c gallows_painter.h config.h)
