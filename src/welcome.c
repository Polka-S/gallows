#include "welcome.h"

void print_welcome() { printf("Hi! Enter your username and select game mode"); }

void enter_username() { printf("Username: "); }

void enter_game_mode() {
    printf("Game mods:\n");
    printf("1 - easy mode\n");
    printf("2 - medium mode\n");
    printf("3 - hard mode\n");
    printf("Enter a number:");
}

int input(char *str) {
    int ch = getchar(), i = 0;
    if ((char)ch != ' ' && (char)ch != '\n') add_char_to_str(str, ch, i);

    while (ch != '\n') {
        if ((char)ch == ' ') {
            ch = getchar();
            continue;
        }
        add_char_to_str(str, ch, i);
        ch = getchar();
    }

    if (i == 0) return ERROR;

    return SUCCESS;
}

void add_char_to_str(char *str, int ch, int *len) {
    str[*len] = (char)ch;
    (*len)++;
}

int check_game_mode(char *str) {
    if (str[0] == EASY_STR) return EASY;
    if (str[0] == MEDIUM_STR) return MEDIUM;
    if (str[0] == HARD_STR) return HARD;
    return ERROR;
}

int welcome(char *username, int *game_mode) {
    int error_code;
    char *game_mode_str;
    print_welcome();
    logcat(info, "The user was greeted");
    enter_username();
    error_code = (username);
    if (error_code) {
        logcat(warning, "The user entered non-valid username: [%s]", username);
        return ERROR;
    }
    
    logcat(warning, "The user entered valid username: [%s]", username);

    enter_game_mode();
    *game_mode = input(game_mode_str);

    if (*game_mode) {
        logcat(warning, "The user entered non-valid game_mode: %d", *game_mode);
        return ERROR;
    }
    
    logcat(warning, "The user entered valid game_mode: %d", *game_mode);

    return SUCCESS;
}