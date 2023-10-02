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

int check_valid_input(char *ch) {
    char finish_input[MAX_SIZE_STR];
    read_input(finish_input);
    int i = 0;

    for (; finish_input[i] != '\0'; i++) {
        if (!is_alpha(finish_input[i])) return ERROR;
        if (i > 0) return ERROR;
    }

    *ch = finish_input[0];

    return i == 0 ? ERROR : SUCCESS;
}

// user_word - массив символов, которые пользователь уже угадал

void answer(char *finish_word, char *user_word) {
    char finish_char;
    int error_code = check_valid_input(&finish_char);
    while (error_code) {
        print_try_again();
        error_code = check_valid_input(&finish_char);
    }

    int count_replace = 0;

    for (int i = 0; finish_word[i] != '\0'; i++) {
        if (finish_char == finish_word[i]) {
            user_word[i] = finish_char;
            count_replace++;
        }
    }

    if (!count_replace)
        print_fail();
    else {
        print_success();
        print_str(user_word);
    }
}
