#include <stdio.h>
#include <stdlib.h>

#define N 5

enum month{
    jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

const char* months[] = {
    "January", "February", "March", "April", "May", "June", "July", 
    "August", "September", "October", "November", "December"
};

const int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

typedef enum month month;


typedef struct date{
    int day;
    month mnth;
} date;


date* next_date(date* d){
    date* next_d = malloc(sizeof(date));
    next_d -> day = d -> day + 1;
    next_d -> mnth = d -> mnth;
    if(next_d -> day > days[d -> mnth]){
        next_d -> day = 1;
        next_d -> mnth = ((next_d -> mnth)+1)%12;
    }
    return next_d;
}

void print_date(date* d){
    printf("%d, %s\n", d -> day, months[d -> mnth]);
}

int main(){
    date dates[N];
    
    dates[0].day = 1;
    dates[0].mnth = jan;
    dates[1].day = 28;
    dates[1].mnth = feb;
    dates[2].day = 14;
    dates[2].mnth = mar;
    dates[3].day = 31;
    dates[3].mnth = oct;
    dates[4].day = 31;
    dates[4].mnth = dec;
    
    for(int i = 0; i<N; i++){
        printf("Today is\n");
        print_date(&dates[i]);
        printf("The next day is\n");
        print_date(next_date(&dates[i]));
        printf("\n");
    }
    return 0;
}