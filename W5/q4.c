// given a uint32_t, extracts and returns the middle six bits.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int middle_six_bits(uint32_t input);

int main(void) {

    printf("please give input:\n");

    uint32_t input;
    scanf("%d", &input);


    printf("the middle six bits of 0x%03X are 0x%03X\n", input, middle_six_bits(input));



    return 0;
}


int middle_six_bits(uint32_t input) {
    // ???? ???? ???? ?!!! !!!? ???? ???? ???? >>> 13
    // approach 1
    // >> 13, then mask 6 bits
    input = input >> 13;
    // mask = 0b 11 1111 = 0x3F
    int mask = 0x3F;
    input = input & mask;

    return input;

    // approach 2
    // << 13, then >> 26

}