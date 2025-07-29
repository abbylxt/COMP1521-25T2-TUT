#include <stdio.h>
#include <stdlib.h>

int utf8_char_length(unsigned char byte) {
    if ((byte & 0x80) == 0) {     // byte & 0b1000 0000 = 0, return 1
        return 1;
    }//         = 0x80
    // byte & 0b1110 0000 = 0b1100 0000, return 2
    //          = 0xE0       0xC0
    if ((byte & 0xE0) == 0xC0) { 
        return 2;
    }
    // byte & 0b1111 0000 = 0b1110 0000, return 3
    //          = 0xF0        0xE0
    if ((byte & 0xF0) == 0xE0) { 
        return 3;
    }
    // byte & 0b1111 1000 = 0b1111 0000, return 4
    //          = 0xF8         0xF0
    if ((byte & 0xF8) == 0xF0) { 
        return 4;
    }
    return -1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return 1;
    }

    int count = 0;
    char *bytes = argv[1];

    int i = 0;
    while (bytes[i] != '\0') {
        i += utf8_char_length(bytes[i]);
        count++;
    }

    printf("there are %d codepoints in the string\n", count);
    return 0;
}