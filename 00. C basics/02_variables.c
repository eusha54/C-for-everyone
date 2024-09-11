// Declaring variables and using in output

#include <stdio.h>

int main(void){
    int num1 = 5;
        // stores the value 5 in num variable
        // variables are like buckets, 
        // can store any number
    printf("The number is : %d\n", num1);
        // %d is placeholder for the "num" variable
        // it determines where to place the variable in the print string


    int num2 = 6;
    printf("%d + %d = %d\n", num1, num2, num1 + num2);
        // printing multiple variables

    // constant variable
    const int num = 100;
        // once declared can't be modified later

    return 0;
}