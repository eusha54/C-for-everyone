#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 1000
#define EMPTY -1
#define FULL (MAX_LEN-1)

typedef struct{char s[MAX_LEN]; int top;} stack;

void reset(stack *stk){ stk -> top = EMPTY;}

void push(char c, stack* stk){stk -> top++; stk -> s[stk->top] = c;}

char pop(stack *stk){return stk -> s[stk->top--];}

char top(const stack *stk){
    return stk -> s[stk->top];
}

int is_empty(const stack *stk){return (stk->top==EMPTY);}
int is_full(const stack *stk){return (stk->top==FULL);}

int main(){
    stack stk_of_chr;
    char *str = "i am otto am i";
    char str_back[20];
    int i=0;
    reset(&stk_of_chr);
    while(str[i] != '\0'){
        printf("%c\n", str[i]);
        push(str[i], &stk_of_chr);
        i++;
    }
    i=0;
    while(!is_empty(&stk_of_chr) && i<20){
        str_back[i] = pop(&stk_of_chr);
        i++;
    }
    printf("reverse is : %s\n", str_back);
}

/*
clarification

#include<stdio.h>

struct Point {
    int x;
    int y;
};

int main() {
    struct Point p1 = {10, 20}; // Regular variable of type struct Point
    struct Point *p2 = &p1;    // Pointer to p1

    // Accessing members of p1 using the dot operator
    printf("p1.x = %d, p1.y = %d\n", p1.x, p1.y);

    // Accessing members of the structure pointed by p2 using the arrow operator
    printf("p2->x = %d, p2->y = %d\n", p2->x, p2->y);

    return 0;
}


*/