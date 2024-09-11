// introducing data types in C
/*
earlier we have seen how to declare a varaible and use it in printf statement.
but it was only a number. we can also store characters, large number, floating points etc in C.
*/


#include <stdio.h>

int main(){
    int num = 2147483647;       // 4 bytes, stores integers
    float frac = 2.35435;       // 4 bytes, stores fractions
    char c = 'A';               // 1 byte, stores char, letter, num or ascii val


    printf("Num is  \t: %d\n", num);
    printf("Frac is \t: %f\n", frac);
    printf("Char is \t: %c\n", c);
        // %d, %f, %c is placeholder for num, float and char type data
    printf("Frac shorted\t\t: %.2f\n", frac);
        // using .2 in %f tells to print only 2 digit after decimal point

    /*
    int is a 4 byte as well as 4*8 = 32 bit storage. so it can only store upto 2^32 numbers
    which is equivalent to -2^31 to 2^31 range. if we need to store larger integer we can use 
    long int, or long long int
    */

    long long int big_num = 9223372036854775807;
        // 8 bytes or 64 bit storage for integers
    double big_frac = 3.333333333333333;
        // 8 bytes and upto 15-16 decimal digits
        // where float stores 4 bytes, or 6-7 digits after decimal point

    printf("Long int is \t\t: %lld\n", big_num);
    printf("Double is \t\t: %lf\n", big_frac);

        // if interested google unsigned long long int
    return 0;
}