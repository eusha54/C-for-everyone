// use of loops

#include <stdio.h>

int main(){
    int i, n = 3;
        // n is loop size
    
    printf("using for loop\n");
    for(i=0; i<n; i++){
        printf("%d\n",i);
    }

    printf("using while loop\n");
    i=0;
    while (i<n){
        printf("%d\n",i);
        i++;
    }

    printf("using do while loop\n");
    i=0;
    do{
        printf("%d\n",i);
        i++;
    } while (i<n);
    
    return 0;
}