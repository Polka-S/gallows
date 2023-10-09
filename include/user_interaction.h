#ifndef USER_INTERACTION_H
#define USER_INTERACTION_H

#define MAX_SIZE_STR 256
#define MAX_SIZE_WORD 10

#define ERROR 1
#define SUCCESS 0

#define TRUE 1
#define FALSE 0

#define EXIT -1
#define NO_EXIT 1

#include <stdio.h>
#include <string.h>

#include "user_interaction.h"

int answer(const char *finish_word, char *user_word, int *count_attempt, char *mistakes);
char to_lower(char ch);

#endif  // USER_INTERACTION_H