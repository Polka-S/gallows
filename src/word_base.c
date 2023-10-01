#include "word_base.h"

char easy_words[EASY_LEN][MAX_WORD_SIZE] = {
        "please","speak","nice","question","yesterday",
        "ticket","change","police","meat","busy"
};
char medium_words[MEDIUM_LEN][MAX_WORD_SIZE] = {
        "everybody","husband","especially","together","thousand",
        "language","instrument","neighbour","determine","property"
};
char hard_words[HARD_LEN][MAX_WORD_SIZE] = {
        "literally","irregardless","nonplussed","lieutenant","performance",
        "accommodation","millennium","ticketinspector","quicksand","dragonfly"
};


char *rand_word_array(char words[][MAX_WORD_SIZE], int size) {
    int random_number = rand() % (size);
    char *random_word = words[random_number];
    return random_word;
}

char* random_easy_word() {
    return rand_word_array(easy_words, EASY_LEN);
}

char* random_medium_word() {
    return rand_word_array(medium_words, MEDIUM_LEN);
}

char* random_hard_word() {
    return rand_word_array(hard_words, HARD_LEN);
}

void start_random_generator() {
    srand(time(NULL));
}