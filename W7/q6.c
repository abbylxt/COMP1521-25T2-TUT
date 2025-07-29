#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t six_middle_bits(uint32_t u) {

    return u;
}

int main(void) {
    uint32_t num = 0x00F9AEB0; // 0b 0000 0000 1111 1001 1010 1110 1011 0000
    // mid six =                                     001 101
    // hex = ??
    printf("%d\n", num);
    printf("0x%0x\n", six_middle_bits(num));
    return EXIT_SUCCESS;
}