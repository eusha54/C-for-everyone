#include<stdio.h>

typedef struct{int x; int y;} pt;

int main() {
    pt p1 = {10, 20}; // Regular variable of type struct Point
    pt *p2 = &p1;    // Pointer to p1

    // Accessing members of p1 using the dot operator
    printf("p1.x = %d, p1.y = %d\n", p1.x, p1.y);

    // Accessing members of the structure pointed by p2 using the arrow operator
    printf("p2->x = %d, p2->y = %d\n", p2->x, p2->y);

    return 0;
}