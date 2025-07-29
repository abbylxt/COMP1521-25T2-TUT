#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
    int16_t num_i = 0x0001; // 1
    int16_t num_ii = 0x0064; // 100
    int16_t num_vi = 0xfffb; // -5
    int16_t num_vii = 0xff9C; // -100

    printf("%d\n", num_i);
    printf("%d\n", num_ii);
    printf("%d, o%o\n", num_vi, num_vi);
    printf("%d, o%o\n", num_vii, num_vii);


    return EXIT_SUCCESS;
}