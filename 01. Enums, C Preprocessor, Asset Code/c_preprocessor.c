#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEPHANT_SEAL_WT_MALE 8800
#define MIN_ELEPHANT_SEAL_WT_MALE 4400

/*note female range is 800-2000*/

/*produce a macro that randomly generates a make weight*/

#define RANGE (MAX_ELEPHANT_SEAL_WT_MALE - MIN_ELEPHANT_SEAL_WT_MALE)
#define POPULATION 1000
#define WEIGHT (rand()%RANGE + MIN_ELEPHANT_SEAL_WT_MALE)
#define FILL for(i=0; i<POPULATION; i++){\
                data[i] = WEIGHT;\
            }\
                    // for every i, FILL generates new WEIGHT

void print_data(int d[POPULATION]){
    int i;
    for (i = 0; i < POPULATION; i++){
        printf("%d\t", d[i]);
        if((i+1)%10==0) printf("\n");
    }
}

int main(){
    int i;
    int data[POPULATION];
    srand(time(0));
    FILL;
        // calls FILL macro using pre defined variables i and data
    print_data(data);
    printf("\n\n");
    return 0;
}
