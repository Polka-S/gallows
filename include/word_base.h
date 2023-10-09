#ifndef GALLOWS_WORD_BASE_H
#define GALLOWS_WORD_BASE_H

#include <stdlib.h>
#include <time.h>

#define MAX_WORD_SIZE 40
#define EASY_LEN 10
#define MEDIUM_LEN 10
#define HARD_LEN 10

const char* random_easy_word();
const char* random_medium_word();
const char* random_hard_word();

void start_random_generator();
#endif  // GALLOWS_WORD_BASE_H
