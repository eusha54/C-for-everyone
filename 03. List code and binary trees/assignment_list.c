/*
Use the linear linked list code to store a randomly generated set of 100 integers.  Now write a routine that will rearrange the list in sorted order of these values. Note you might want to use bubble sort to do this. Print these values in rows of 5 on the screen.

How will this work? Compare two adjacent list elements and if they are out of order swap them. After a first pass the largest element will have bubbled to the end of the list. Each pass can look at one less element as the end of a list stays sorted.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
            // defining size of randomly generated list

typedef struct list{
            // defining list structure
    int num;
    struct list* next;
} list;


list *create_list(int data){
            // creating a list item and returning the pointer location of the item
    list* head = malloc(sizeof(list));
            // allocating memory for list item
    head -> num = data;
    head -> next = NULL;
    return head;
}

list *add_to_front(list* h, int data){
    list* head = create_list(data);
            // creates a new list item with given data
    head -> next = h;
            // linking the existing list with the new item 
            // the new item is the head of list now
    return head;
}

list* arr_to_list(int arr[SIZE]){
    list* head = create_list(arr[0]);
            // initializing the first list item
    for(int i=1; i<SIZE; i++){
        head = add_to_front(head, arr[i]);
            // adding each of the array element to the top of previous list item
    }
    return head;
}

void list_print(list* l){
    list* h = l;
        // copying list head ptr to another variable so that original pointer stays unchanged
    int i = 0;
    while(h != NULL){
            // loops and prints every item until the heading is null
            // the next head of the last element is null
        if(i%5==0) printf("\n");
        printf("%d  ", h->num);
        h = h->next;
        i++;
    }
    printf("\n");
}

void swap(list* h1, list* h2){
        // swaps two list items 
    list* temp = malloc(sizeof(list));
    temp -> num = h1 -> num;
    h1 -> num = h2 -> num;
    h2 -> num = temp -> num;
    free(temp);
        // freeing memory to increase efficiency
}

int pass(list* h){
        // running through the entire list to check if any element[i] is greater than element[i+1]
        // if so those items are swapped
    list* temp = h;
    int swaped = 0;
    while(h->next != NULL){
        if(h->num > (h->next)->num){
            swaped=1;
            swap(h, h->next);
        }
        h = h->next;
    }
    h = temp;
    return swaped;
        /*
        even if a single swap is made, the func returns 1, 
        if no swap made, func returns 0
        */
}

int main(){
    int rand_nums[SIZE];
    int i;
    srand(time(NULL));
    
    for(i=0; i<SIZE; i++){
        rand_nums[i] = rand()%900 + 100;
            // creating an array of random numbers
    }
    

    list* head = arr_to_list(rand_nums);
            // creating list from array and storing the head ptr of list
    list_print(head);
    
    while(pass(head));
        /* after each run through the list, 
        if a single swap is made pass returns 1,
        so the while loop continues, if no swap is made
        then there is no element such that,
        element[i] is greater than element[i+1].
        Thus the list is rearranged
        */

    list_print(head);
    return 0;
}