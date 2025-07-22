#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LENGTH 8192

void search_file(FILE *file, char *needle) {
    char line[MAX_LENGTH];
    char line_no = 0;
    while (fgets(line, MAX_LENGTH, file)) {
        if (strstr(line, needle) != NULL){
            printf("%d: %s\n", line_no, line);
        }
        line_no++;
    }
}
// Write a C program, fgrep.c, which is given 1+ command-line arguments which is a string to search for.
// If there is only 1 command-line argument it should read lines from stdin and print them to stdout iff they contain the string specified as the first command line argument.

// If there are 2 or more command line arguments, it should treat arguments after the first as filenames and print any lines they contain which contain the string specified as the first command line arguments.

// When printing lines your program should prefix them with a line number.

// It should print suitable error messages if given an incorrect number of arguments or if there is an error opening a file.

int main(int argc, char *argv[]) {

    // This program should only run for argc == 2
    if (argc < 2) {
        fprintf(stderr, "Usage: at least 1 command line arg");
        exit(1);
    }
    if (argc == 2) {
        search_file(stdin, argv[1]);
        return 0;
    }
    if (argc > 2) {
        for (int i = 2; i < argc; i++) {
            FILE *input = fopen(argv[i], "r");
            if (input == NULL) {
                perror("failed to open file:");
                return 0;
            }

            search_file(input, argv[1]);
        }
        return 0;
    }
}