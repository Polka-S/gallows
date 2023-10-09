#include "welcome.h"

#include <unistd.h>

void print_welcome() { printf("Hi! Enter your username and select game mode\n"); }

void enter_username() { printf("Username: "); }

void enter_game_mode() {
    printf("Game mods:\n");
    printf("1 - easy mode\n");
    printf("2 - medium mode\n");
    printf("3 - hard mode\n");
    printf("Enter a number: ");
}

void print_try_it_again() { printf("I don't understand. Try again: "); }

void add_char_to_str(char *str, int ch, int *len) {
    str[*len] = (char)ch;
    (*len)++;
}

int input(char *str) {
    int ch = getchar(), i = 0;
    if ((char)ch != ' ' && (char)ch != '\n') add_char_to_str(str, ch, &i);

    while (ch != '\n') {
        ch = getchar();
        if ((char)ch != ' ' && (char)ch != '\n') add_char_to_str(str, ch, &i);
    }

    if (i == 0) return ERROR;

    return SUCCESS;
}

int check_game_mode(const char *str) {
    if (str[0] == EASY_STR || str[0] == MEDIUM_STR || str[0] == HARD_STR) return SUCCESS;
    return ERROR;
}

void valid_game_mode(char *game_mode_str, int *game_mode) {
    int error_code = input(game_mode_str);

    while (error_code || check_game_mode(game_mode_str) == ERROR) {
        logcat(warning, "The user entered non-valid game_mode: %s", game_mode_str);
        print_try_it_again();
        error_code = input(game_mode_str);
    }

    if (game_mode_str[0] == EASY_STR) *game_mode = EASY;
    if (game_mode_str[0] == MEDIUM_STR) *game_mode = MEDIUM;
    if (game_mode_str[0] == HARD_STR) *game_mode = HARD;
}

void welcome(char *username, int *game_mode) {
    char game_mode_str[255];

    if (*game_mode != EASY && *game_mode != MEDIUM && *game_mode != HARD) {
        int error_code;
        print_welcome();
        logcat(info, "The user was greeted");
        enter_username();
        error_code = input(username);

        while (error_code) {
            logcat(warning, "The user entered non-valid username: [%s]", username);
            print_try_it_again();
            error_code = input(username);
        }

        logcat(info, "The user entered valid username: [%s]", username);
    }

    enter_game_mode();
    valid_game_mode(game_mode_str, game_mode);

    logcat(info, "The user entered valid game_mode: %d", *game_mode);
    printf("Thank you, %s! To exit the game, enter 'exit'", username);
}