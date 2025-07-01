#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
    // first convert them to binary
    // Hint: each number in hex, represents four bits in binary

    uint16_t a = 0x5555;
    //       5 = 0b0101
    //       a = 
    uint16_t b = 0xAAAA;// A = 10
    //     0xA = 10 = 0b1010
    //       b = 
    uint16_t c = 0x0001;
    //       c = 

    // a     = 0101 0101 0101 0101
    // b     = 1010 1010 1010 1010
    // a | b = 
    printf("0x%04X\n", a | b); // 0x????

    // a     = 0101 0101 0101 0101
    // b     = 1010 1010 1010 1010 
    // a & b = 
    printf("0x%04X\n", a & b); // 0x

    // a     = 0101 0101 0101 0101
    // b     = 1010 1010 1010 1010 
    // a ^ b = 
    printf("0x%X\n", a ^ b); // 0x

    // b     = 1010 1010 1010 1010
    // ~b    = 

    // a      = 0101 0101 0101 0101 
    // ~b     = 
    // a & ~b = 
    printf("0x%X\n", a & ~b); // 0x

    // c      = 0000 0000 0000 0001
    // c << 6 = 
    printf("0x%04X\n", c << 6); // 0x????

    // a      = 0101 0101 0101 0101 
    // a >> 4 = 
    printf("0x%04X\n", a >> 4); // 0x????

    // b            = 1010 1010 1010 1010
    // b << 1       = 

    // a            = 0101 0101 0101 0101 
    // a & (b << 1) =  = 0x
    printf("0x%04X\n", a & (b << 1));

    // b            = 1010 1010 1010 1010  
    // c            = 0000 0000 0000 0001        c is a mask which isolates the last digit of the b
    // b & c        =  = 0x
    printf("0x%04X\n", b & c);

    // b            = 1010 1010 1010 1010  
    // c            = 0000 0000 0000 0001        c is a mask which isolates the last digit of the a
    // b | c        =   = 0x????
    printf("0x%04X\n", b | c);            

    return EXIT_SUCCESS;
}