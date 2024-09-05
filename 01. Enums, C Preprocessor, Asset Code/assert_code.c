#include<assert.h>
#include<stdio.h>
// #include<ctype.h>

int main(){
    assert(1);
    printf("My program runs\n");
    return 0;
}
int main2(){
    float x,y;
    while(1){
        printf("Read in two floats:\n");
        scanf("%f%f", &x,&y);
        assert( y!=0);
            // inside assert any condition, 
            // if condition true(1) code runs except ends
            
            // y can be any value except 0
            // if y == 0, program ends
        printf("x / y = %f\n", x/y);
    }
}