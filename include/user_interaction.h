#ifndef USER_INTERACTION_H
#define USER_INTERACTION_H

#define MAX_SIZE_STR 256
#define MAX_SIZE_WORD 10

#define ERROR 1
#define SUCCESS 0

#define TRUE 1
#define FALSE 0

#include <stdio.h>

#include "user_interaction.h"

void answer(const char *finish_word, char *user_word, int *count_attempt);

#endif  // USER_INTERACTION_H