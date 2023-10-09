#ifndef USER_INTERACTION_H
#define USER_INTERACTION_H

#include <stdio.h>
#include <string.h>

#include "config.h"
#include "user_interaction.h"

int answer(const char *finish_word, char *user_word, int *count_attempt, char *mistakes);
char to_lower(char ch);

#endif  // USER_INTERACTION_H