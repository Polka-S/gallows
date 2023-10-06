#include "gallows_painter.h"

FILE *open_gallows_states_file() {
    FILE *gallows_states_file = fopen(GALLOWS_STATES_FILE_NAME, "r");

    if (!gallows_states_file) {
        logcat(error, "Error while reading gallows states parameters");
        printf("Error while reading gallows states parameters\n");
        _Exit(EXIT_FAILURE);
    }

    return gallows_states_file;
}

void read_parameters(FILE *gallows_states_file, int *states_amount_arg, int *state_height_arg) {
    int states_amount = 0, state_height = 0;
    char parameter[MAX_PARAMETER_LEN + 1];

    for (int i = 0; i < 2; i++) {
        fscanf(gallows_states_file, "%" MAX_PARAMETER_LEN_STR "s", parameter);
        if (strcmp(parameter, "STATES_AMOUNT") == 0) {
            logcat(info, "read STATES_AMOUNT parameter");
            fscanf(gallows_states_file, "%d", &states_amount);
        }
        if (strcmp(parameter, "STATE_HEIGHT") == 0) {
            logcat(info, "read STATE_HEIGHT parameter");
            fscanf(gallows_states_file, "%d", &state_height);
        }
    }

    if (states_amount == 0 || state_height == 0 || states_amount != MAX_GALLOWS_ELEMS) {
        logcat(error, "Error while reading gallows states parameters");
        _Exit(EXIT_FAILURE);
    }

    fgets(parameter, MAX_STRING_LEN, gallows_states_file);

    *states_amount_arg = states_amount;
    *state_height_arg = state_height;
}

void skip_states(FILE *gallows_states_file, int states_to_skip, int state_height) {
    char *estr, string[MAX_STRING_LEN + 1];
    for (int i = 0; i < states_to_skip; i++) {
        for (int j = 0; j < state_height; j++) {
            estr = fgets(string, MAX_STRING_LEN, gallows_states_file);

            if (!estr) {
                logcat(error, "Error while reading states");
                printf("Error while reading states\n");
                _Exit(EXIT_FAILURE);
            }
        }
    }
}

void print_one_state(FILE *gallows_states_file, int state_height) {
    char string[MAX_STRING_LEN + 1];
    for (int i = 0; i < state_height; i++) {
        char *estr;
        estr = fgets(string, MAX_STRING_LEN, gallows_states_file);

        if (!estr) {
            logcat(error, "Error while reading states");
            _Exit(EXIT_FAILURE);
        }

        printf("%s%s", LEFT_MARGIN, string);
    }
}

void draw_gallows(int elems) {
    FILE *gallows_states_file = open_gallows_states_file();
    int states_amount = 0, state_height = 0;

    read_parameters(gallows_states_file, &states_amount, &state_height);

    skip_states(gallows_states_file, elems, state_height);

    print_one_state(gallows_states_file, state_height);
    logcat(info, "Printed state %d", elems);

    fclose(gallows_states_file);
}
