#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LENGTH 8192

// which is given one command-line argument, 
// the name of a file, 
// and which prints the first line of that file to stdout. 
// If given an incorrect number of arguments, or if there was an error opening the file, 
// it should print a suitable error message.
int main(int argc, char *argv[]) {
    // This program should only run for argc == 2
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    FILE *output = fopen(argv[1], "w");
    if (output == NULL) {
        perror("failed to open file:");
        return 0;
    }

    
    char string[MAX_LENGTH];
    fgets(string, MAX_LENGTH, stdin);
    fputs(string, output);
}