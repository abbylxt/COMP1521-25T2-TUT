// prints out contents of $HOME/.diary

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *filename = ".diary";

int main(void) {
    // Create pathname $HOME/.diary

    // Get the environment variable for home
    char *value = getenv("HOME");
    int len = strlen(value) + strlen(filename) + 2;
    char full_pathname[len];

    snprintf(full_pathname, len, "%s/%s", value, filename);

    FILE *input = fopen(full_pathname, "r");

    if (input == NULL) {
        perror("");
    }
 
    char line[1096];
    while (fgets(line, 1096, input) != NULL) {
        fputs(line, stdout);
    }

    fclose(input)
    return 0;

}