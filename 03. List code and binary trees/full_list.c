#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct list{
    int data;
    struct list *next;
} list;

int is_empty(const list *l){
    return (l==NULL);
}

list* create_list(int d){
    list* head = malloc(sizeof(list));
    head -> data = d;
    head -> next = NULL;
    return head;
}

list* add_to_front(int d, list* h){
    list* head = create_list(d);
    head -> next = h;
    return head;
}

list* array_to_list(int d[], int size){
    list* head = create_list(d[0]);
    int i;
    for(i=1; i<size; i++){
        head = add_to_front(d[i], head);
    }
    return head;
}

void print_list(list *h, char *title){
    printf("%s\n", title);
    while(h!=NULL){
        printf("%d :", h ->data);
        h = h-> next;
    }
}

int main(){
    list list_of_int;
    list* head = NULL;
    int data[6] = {2,3,4,5,6,7};
    int size  = sizeof(data)/sizeof(data[0]);
    head = array_to_list(data, size);
    print_list(head, "data[6] made into 6 element list");
    printf("\n\n");
    return 0;
}



// // Simple Version of full list

// #include <stdio.h>
// #include <stdlib.h>

// #define SIZE 10

// typedef struct list{
//     int data;
//     struct list* next;
//         // * is used, as 'next' will store memory address of the next list item
// } list;
//     // declaring a list structure
//     // which carries one list item and the next item's memory address

// int main(){
//     list num_list;
//     list* head = malloc(sizeof(list));
//         // allocating memory to head
//         // malloc allocates memory according to given size and return memory address 
//     head->data = 0;         
//     head->next = NULL;
//         // using -> as head is a memory address
//         // accessing structure attributes by ->
    
//     for (int i = 1; i < SIZE; i++){
//         list* h = malloc(sizeof(list));
//             // creating another list element, and allocating memory 
//         h->data = i;
//             // setting value 
//         h->next = head;
//             // linking previous item with the current item
//             // putting previous list item's memory address at current element's 'next' attribute 
//         head = h;
//             // now updating 'head' var with current item's memory address 'h'
//     }

//     num_list = *head;
//         // now assigning the final head value to num_list


//     // Loop using head
//     while (head != NULL){
//         printf("%d\n", head->data);
//         head = head->next;
//             // printing current head's item then updating head ptr with next items ptr
//     }
//     printf("\n\n");

//     // Loop using num_list
//     while(1){
//         printf("%d\n", num_list.data);
//         if(num_list.next == NULL) break;
//         num_list = *num_list.next;
//     }

//     return 0;
// }