#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
    // // 1234
    // base 10
    // int dec = 1234; // 10 ^ 3 * 1 + 10 ^ 2 * 2 + 10 ^ 1 * 3 + 10 ^ 0 * 4 = 1234
    // base 16
    // // hex counting: 0 1 2 ... 9 A B C D E F
    // int hex = 0x1234; // (16 ^ 3 * 1) + (16 ^ 3 * 2) + 16 ^ 1 * 3 + 16 ^ 0 * 4 = 4096 + 512 + 48 + 4 = 4,660
    // // oct counting: 0 1 2 ... 7
    // int oct = 01234; // 512 + 128 + 24 + 4 = 668
    // // binary = 0 1
    // int binary = 0b1010; 8 + 2 // 10 (not portable) (not recommend to use in your code)

    // 127
    // int dec = 1234; 
    // hex counting: 0 1 2 ... 9 A B C D E F
    // int hex = 0x1234; //    0x4 = 4 * 16^0 =    4
                      //                      +
                      //   0x30 = 3 * 16^1 =   48
                      //                      +
                      //  0x200 = 2 * 16^2 =  512
                      //                      +
                      // 0x1000 = 1 * 16^3 = 4096
                      //                      =
                      //                     4660
    // oct counting: 0 1 2 ... 8
    // int oct = 0177;  // 0100  = 1 * (8 ^ 2) = 64
                     //                         +
                     // 0070  = 7 * (8 ^ 1) = 56
                     //                         +
                     // 0007  = 7 * (8 ^ 0) = 7
                     //                         =
                     //                        127
    // int binary = 0b1010; // 2 (not portable) (do not to use in your code)
                         // 0b1000 = 1 * 2^3 = 8
                         // 0b0000 = 0 * 2^2 = 0
                         // 0b0010 = 1 * 2^1 = 2
                         // 0b0000 = 0 * 2^0 = 0
                         // total  =  0b1010 = 10
    //  hex to binary    0xF7  = 1111 0111
                         // 0x7 = 7  = 0111 = 4 + 2 + 1 = 2^2 + 2^1 + 2^0
                         // 0xF = 15 = 1111 = 8 + 4 + 2 + 1 = 2^3 + 2^2 + 2^1 + 2^0


    // printf("%d\n", dec);
    // printf("0x%03X = %d\n", hex, hex);
    // printf("0%o = %d\n", oct, oct);
    // printf("%d\n", binary);
    // printf("0x%03X, 0%o\n", hex, oct);
    // printf("0x%03x, 0%o\n", hex, oct);

    // // mini program to print input in octal, hex and dec
    int input;
    scanf("%d", &input);
    printf("input decimcal form = %d\n input hex form  = 0x%04X\n input octal form = 0%o\n", input, input, input);

    return EXIT_SUCCESS;
}