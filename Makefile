.PHONY: all build clean

CC = gcc
FLAGS = -Werror -Wall -Wextra -std=c11

BUILD = ./build
SRC = ./src
INCLUDE = ./include
TARGET = $(BUILD)/build

all: build

build: $(wildcard $(SRC)/*.c)
	$(CC) $(FLAGS) -I$(INCLUDE) $^ -o $(TARGET)

clean:
	rm $(TARGET)





