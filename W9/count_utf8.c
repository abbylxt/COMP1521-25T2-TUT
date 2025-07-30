#include <stdio.h>
#include <stdlib.h>

int utf8_char_length(unsigned char byte) {
    if ((byte & 0x80) == 0) {       // byte & 0b1000 0000 = 0, return 1 bytes
        return 1;                   //         = 0x80
    }
    if ((byte & 0xE0) == 0xC0) {    // byte & 0b1110 0000 = 0b1100 0000, return 2 bytes
        return 2;                   //          = 0xE0       0xC0
    }
    if ((byte & 0xF0) == 0xE0) {    // byte & 0b1111 0000 = 0b1110 0000, return 3 bytes
        return 3;                   //          = 0xF0        0xE0
    }
    if ((byte & 0xF8) == 0xF0) {    // byte & 0b1111 1000 = 0b1111 0000, return 4 bytes
        return 4;                   //          = 0xF8         0xF0
    }
    return -1;                      // otherwise it is an invalid utf8 bytes
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return 1;
    }

    int count = 0;
    char *bytes = argv[1];      // char in c is takes up 1 byte of memory (also 8 bits)
                                // so in c, a string = char array = byte array
                                // therefore we can just iterate through strings like a byte array

    int i = 0;
    while (bytes[i] != '\0') {
        i += utf8_char_length(bytes[i]);    // check how many bytes the current utf8 char takes up
                                            // increase by the no. of bytes to get to the next char
        count++;
    }

    printf("there are %d codepoints in the string\n", count);
    return 0;
}