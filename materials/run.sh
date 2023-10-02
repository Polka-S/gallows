#!/bin/bash

clang-format --style=file:linters/.clang-format ../include/*.h ../src/*.c -i

cppcheck --enable=all --suppress=missingIncludeSystem -I ../include ../src


cd ../
make clean
make

build/build

cd materials