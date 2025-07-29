#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
    uint32_t a = 0x00000000; // 
    uint32_t b = 0x80000000; // 
    uint32_t c = 0x3fc00000; // 
    uint32_t d = 0x3f000000; // 
    uint32_t f = 0x40300000; // 

    float *a_float = (float *)&a;
    float *b_float = (float *)&b;
    float *c_float = (float *)&c;
    float *d_float = (float *)&d;
    float *f_float = (float *)&f;


    printf("%f\n", *a_float);
    printf("%f\n", *b_float);
    printf("%f\n", *c_float);
    printf("%f\n", *d_float);
    printf("%f\n", *f_float);


    return EXIT_SUCCESS;
}