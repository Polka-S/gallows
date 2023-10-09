#ifndef WELCOME_H
#define WELCOME_H

#include "config.h"
#include "logger.h"

#define EASY_STR '1'
#define MEDIUM_STR '2'
#define HARD_STR '3'

void welcome(char *username, int *game_mode);
int input(char *str);
void print_try_it_again();

#endif  // WELCOME_H