#include <stdio.h>

enum day{
    sun, mon, tue, wed, thu, fri, sat
};          // declare type
typedef enum day day;

void print_day(day d){
    switch (d){
    case sun:
        printf(" sunday");
        break;
    
    case mon:
        printf(" monday");
        break;
    
    case tue:
        printf(" tueday");
        break;
    
    case wed:
        printf(" wednesday");
        break;
    
    case thu:
        printf(" thursday");
        break;
    
    case fri:
        printf(" friday");
        break;
    
    case sat:
        printf(" satureday");
        break;
    
    default:
        printf("%d is an error", d);
        break;
    }
}

day tomorrow(day d){
    return ((d+1)%7);
}

day day_after_tomorrow(day d){
    return ((d+2)%7);
}

day yesterday(day d){
    return ((d+6)%7);
}

int main(){
    day today = fri;
    printf("today is \t");
    print_day(today);
    printf("\n\n");    
    printf("tomorrow is \t");
    print_day(tomorrow(today));
    printf("\n\n");
    printf("after tomorrow \t");
    print_day(day_after_tomorrow(today));
    printf("\n\n");
    printf("yesterday was \t");
    print_day(yesterday(today));
    printf("\n\n");
}