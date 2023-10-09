#include "user_interaction.h"

int is_alpha(char ch) { return (('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z')); }

void print_try_again() { printf("Try again: "); }
void print_fail() { printf("This letter is not in the word\n"); }
void print_success() { printf("\nYou guessed the letter!\n"); }

void print_str(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        printf("%c", str[i]);
        if (str[i + 1] != '\0') printf(" ");
    }
}

void add_symbol_to_str(char *str, int symbol, int *i) {
    str[*i] = (char)symbol;
    (*i)++;
}

void read_input(char *input_str) {
    int ch = 0, i = 0;

    while ((char)ch != '\n') {
        ch = getchar();
        if ((char)ch == ' ')
            continue;
        else if ((char)ch == '\n')
            break;

        add_symbol_to_str(input_str, ch, &i);
    }

    add_symbol_to_str(input_str, '\0', &i);
}

char to_lower(char ch) {
    if ('A' <= ch && ch <= 'Z')
        return (char)((int)ch + 32);
    else
        return ch;
}

int check_exit(char *str) {
    if (to_lower(str[0]) == 'e' && to_lower(str[1]) == 'x' && to_lower(str[2]) == 'i' &&
        to_lower(str[3]) == 't' && strlen(str) == 4)
        return EXIT;

    return NO_EXIT;
}

int check_valid_input(char *ch) {
    char finish_input[MAX_SIZE_STR];
    read_input(finish_input);
    int i = 0;

    for (; finish_input[i] != '\0'; i++) {
        if (!is_alpha(finish_input[i])) return ERROR;
        if (check_exit(finish_input) == EXIT) return EXIT;
        if (i > 0) return ERROR;
    }

    *ch = finish_input[0];

    return i == 0 ? ERROR : SUCCESS;
}

void add_to_mistakes(char *mistakes, char mistake) {
    int i = strlen(mistakes);
    mistakes[i++] = mistake;
    mistakes[i] = '\0';
}

int check_old_mistakes(const char *mistakes, char letter) {
    for (int i = 0; mistakes[i] != '\0'; i++) {
        if (letter == mistakes[i]) return ERROR;
    }

    return SUCCESS;
}

int answer(const char *finish_word, char *user_word, int *count_attempts, char *mistakes) {
    char user_letter;

    int error_code = check_valid_input(&user_letter), flag_replay_symbol = FALSE;
    if (error_code == EXIT) return EXIT;

    while (error_code) {
        print_try_again();
        error_code = check_valid_input(&user_letter);
        if (error_code == EXIT) return EXIT;
    }

    int count_replace = 0;

    for (int i = 0; finish_word[i] != '\0'; i++) {
        if (user_letter == finish_word[i] && user_word[i] != '_') flag_replay_symbol = TRUE;

        if (user_letter == finish_word[i]) {
            user_word[i] = user_letter;
            count_replace++;
        }
    }

    if (!flag_replay_symbol && !check_old_mistakes(mistakes, user_letter)) {
        if (!count_replace) {
            (*count_attempts)--;
            print_fail();
            printf("\nNow you have a %d attempts\n", *count_attempts);
            add_to_mistakes(mistakes, user_letter);
        } else
            print_success();
    } else
        printf("You have already guessed this letter.\n");

    print_str(user_word);

    return NO_EXIT;
}
