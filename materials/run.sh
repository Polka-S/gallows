#!/bin/bash

cp linters/.clang-format ../src/.clang-format
cp linters/.clang-format ../include/.clang-format

clang-format ../include/*.h ../src/*.c -i

cppcheck --enable=all --suppress=missingIncludeSystem -I ../include ../src


cd ../
make clean
make

build/build

cd materials