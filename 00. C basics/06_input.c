#include<stdio.h>

int main(){
    int num;
    scanf("%d", &num);
        // takes input 
        // %d means input is a integer type
        // &num is the memory location of num variable
        // where the input will be stored
        // char, float can also be taken as input
    printf("You entered %d \n", num);
    return 0;
}