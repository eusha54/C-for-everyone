/*
Modify the singly linked list to be a doubly linked list. Now write a routine 
that removes all duplicate data in the doubly linked list. The data will be 
integers generated at random from [0,49]. Initially have a list of 200 elements.  

Now do this in one of two ways.  Sort the list by its data field. Remove adjacent 
elements of the sorted list with the same value. Or, take the first element—search 
the remainder of the list for elements with the same data and remove them. Then 
take the second element and do the same. Repeat until only one element is left.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*                  doubly linked list               */

// doubly linked structure
// every elem stores prev and next elem's ptr
typedef struct dlist{
    int data;
    struct dlist*prev;
    struct dlist*next;
}dlist;

// creates a doubly linked list elem
dlist* create_dlist(int d){
    dlist* item = malloc(sizeof(dlist));
    item->data = d;
    item->prev = NULL;
    item->next = NULL;
    return item;
}

// adds another elem to the front of list head
dlist* add_to_front(int d, dlist*h){
    dlist*head = create_dlist(d);
    h->prev = head;
    head->next = h;
    return head;
}



/*                 delete part                */

// deletes any mid value of the list 
// with the elem ptr only
void del_mid(dlist*ele){
    if(ele->next !=NULL){
        ele->prev->next = ele->next; 
        ele->next->prev = ele->prev; 
            // if ele is last ele, then ele->next 
            // equals NULL which has no prev ptr
            // therefore else condition is used
    }else{
        ele->prev->next = NULL;
    }
    free(ele);
}

// deletes any value of the list
// requires head of the list and delete elem
void del(dlist**head, dlist*ele){
    if(ele->prev==NULL){
        dlist*temp = *head;
        *head = ele->next;
        (*head)->prev = NULL;
        free(temp);
    }else del_mid(ele);
}

// deletes duplicated items, using 2nd approach
// ele = elem with which to compare
// chk = elem which will be compared to be deleted or not
void del_dup(dlist*ele, dlist*chk){
    if(chk!=NULL){
        if(ele->data == chk->data){
            del_mid(chk);
        }
        del_dup(ele, chk->next);
    }
}



/*                    other functionalities                */

// generates random list 
// min = the minimum value it will take
// max = the maximum value it will take
// size = num of elem in the list
dlist*random_list(int min, int max, int size){
    int diff = max-min;
    srand(time(NULL));
    dlist*head = create_dlist(min+rand()%diff);
    for(int i=1; i<size; i++){
        head = add_to_front(min+rand()%diff, head);
    }
    return head;
}

// prints the doubly linked list
void dlist_print(dlist*h){
    if (h!=NULL){
        printf("%d   ", h->data);
        dlist_print(h->next);
    }
    else printf("\n");
}

// // this func was used while debuging
// dlist*arr_to_list(int*arr, int size){
//     dlist*head = create_dlist(arr[0]);
//     for(int i=1; i<size; i++){
//         head = add_to_front(arr[i],head);
//     }
//     return head;
// }



int main(){
    dlist*head = random_list(0,50,100);

    printf("\nOriginal list\n");
    dlist_print(head);
        // creating and printing a random list of 200 elem with range [0,49]

    dlist*ele = head;
        // copying list head so that original doesnt change
    while(ele->next!=NULL){
        del_dup(ele, ele->next);
            // comparing the del_dup func for every element of the list
        ele = ele->next;
    }
    printf("\nDuplicate free list\n");
    dlist_print(head);
        // printing the duplicate free list
    return 0;
}






