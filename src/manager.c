#include "manager.h"

int check_str(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '_') return FALSE;
    }

    return TRUE;
}

void complete_word(const char *word, char *usr_word) {
    int i = 0;
    for (; word[i] != '\0'; i++) {
        usr_word[i] = '_';
    }

    usr_word[i] = '\0';
}

void print_mistakes(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        printf("%c", str[i]);

        if (str[i + 1] != '\0') printf(", ");
    }
}

void game_logic(const char *word, char *usr_word, int *exit_flag) {
    int count_attempts = 8;
    char mistakes[MAX_SIZE_STR];
    mistakes[0] = '\0';

    while (!check_str(usr_word) && count_attempts > 0) {
        logcat(info, "The user has not guessed the word yet. Word: [%s]", usr_word);
        printf("\nEnter the letter: ");
        if (answer(word, usr_word, &count_attempts, mistakes) == EXIT) {
            *exit_flag = EXIT;
            return;
        }

        if (strlen(mistakes)) {
            printf("\n\nYour mistakes: ");
            print_mistakes(mistakes);
        }
        printf("\n");
        draw_gallows(8 - count_attempts - 1);
    }
}

int is_yes_no(const char *str) { return str[0] == 'y' || str[0] == 'n'; }

int restart_game(char *user_answer) {
    int error_code = input(user_answer);

    while (error_code && is_yes_no(user_answer)) {
        print_try_it_again();
        error_code = input(user_answer);
    }

    user_answer[0] = to_lower(user_answer[0]);

    return user_answer[0] == 'y';
}

void run() {
    char username[MAX_SIZE_STR];
    char restart[MAX_SIZE_STR];
    char restart_ch = 'y';
    int exit_flag = NO_EXIT;

    while (restart_ch == 'y') {
        const char *word = NULL;
        start_random_generator();
        int game_mode;
        welcome(username, &game_mode);

        if (game_mode == EASY) word = random_easy_word();
        if (game_mode == MEDIUM) word = random_medium_word();
        if (game_mode == HARD) word = random_hard_word();

        char usr_word[MAX_SIZE_WORD];

        logcat(info, "Initialize word [%s]", word);

        complete_word(word, usr_word);
        logcat(info, "The user's string is filled with '_'. String now: [%s]", usr_word);

        logcat(info, "The game has started.");
        game_logic(word, usr_word, &exit_flag);

        if (exit_flag == EXIT) return;

        printf("\n\n============================\n");
        printf("The hidden word: %s\n", word);

        if (!check_str(usr_word)) {
            printf("You are loh");
        } else
            printf("You are not a loh");

        printf("\n\nDo you want to play again? y/n: ");

        if (restart_game(restart))
            restart_ch = 'y';
        else
            restart_ch = 'n';

        printf("\n");
    }
}