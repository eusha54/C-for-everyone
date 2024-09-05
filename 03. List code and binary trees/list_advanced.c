/*
4 basic operations of list, implemented here
    1. insert
    2. count
    3. concat
    4. delete
other operations are
    5. element by index
    6. replace
    7. list print
    8. array to list
*/




#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/*              initializing list              */

// list item structure
typedef struct list{
    int data;
    struct list*next;
} list;

// checking if the list item is empty or not
// if empty returns 1
int is_empty(list*h){
    if(h == NULL) return 1;
    return 0;
}

// creating list item described in full listt
list* create_list(int d){
    list* head = malloc(sizeof(list));
    head -> data = d;
    head -> next = NULL;
    return head;
}

// adding another item to the front of any list
list* add_to_front(int d, list* h){
    list* head = create_list(d);
    head -> next = h;
    return head; 
}




/*              4 basic list operation              */

// inserting data at i th index
void insert(int d, int i, list**h){
    if(i==0) *h = add_to_front(d, *h);
    else if(i==1){
        list*head = malloc(sizeof(list));
        head->data = d;
        head->next = (*h)->next;
        (*h)->next = head;
    }
    else insert(d, i-1, &((*h)->next));
}


// getting length of the list
int count(list* h){
    int cnt=0;
    while (!is_empty(h)){
        cnt++;
        h = h->next;
    }
    return cnt;
}


// concatenating 2 list with the head of first 1
void concat(list* h1, list* h2){
    if(is_empty(h1->next)) h1->next = h2;
    else concat(h1->next, h2);
}



/*      deletes item using list head and element (to be dlt) ptr       */

// recursion part of the delete function
void delete_recurse(list*h, list*ele){
    if(h->next != NULL){
        if(h->next == ele){
            list* temp = h->next;
            h->next = h->next->next;
            free(temp);         // freeing the existing memory
        } 
        else delete_recurse(h->next, ele);
    }
}

// this function checks if the dlt ele is first ele of list or not
// if not this func calls its recursive version to check for the ele recursively
void delete(list**h, list*ele){
    if(*h==ele){
        list*temp = *h;
        *h = (*h)->next;
        free(temp);             // freeing the existing memory
    } 
    else delete_recurse(*h, ele);
}



/*      deletes item using list head and element (to be dlt) val       */

// recursion part of the delete_val function
void delete_val_recurse(list*h, int val){
    if(h->next != NULL){
        if(h->next->data == val) delete_recurse(h, h->next);
        else delete_val_recurse(h->next, val);
    }
}

// this function checks if the dlt ele is first ele of list or not
// if not this func calls its recursive version to check for the ele recursively
void delete_val(list**h, int val){
    if((*h)->data == val) delete(&(*h), *h);
    else delete_val_recurse(*h, val);
}



/*      deletes item using list head and element (to be dlt) index       */

// recursion part of the delete_index function
void delete_index_recurse(list*h, int i){
    if(h->next != NULL){
        if(i==1) delete_recurse(h, h->next);
        else delete_index_recurse(h->next, i-1);
    }
}

// this function checks if the dlt ele is first ele of list or not
// if not this func calls its recursive version to check for the ele recursively
void delete_index(list**h, int i){
    if(i==0) delete(&(*h),*h);
    else delete_index_recurse(*h, i);
}


// deletes entire list
void delete_list(list**h){
    if(*h != NULL){
        list *temp = *h;
        *h = (*h)->next;
        free(temp);
        delete_list(&(*h));
    }
}



/*              other operations           */

// getting i index value of the list
list* list_i(list* h, int i){
    if(i==0) return h;
    else list_i(h->next, i-1);
}


// replacing data at i th index
void replace(int new_d, int i, list**h){
    delete_index(&(*h), i);
    insert(new_d,i,&(*h));
}


// printing list
void print_list(list* h){
    if(!is_empty(h)){
        printf("%d   ", h->data);
        print_list(h -> next);
    }
    else printf("\n");
}



// converting array into list
list* array_to_list(int d[], int n){
    list* h = create_list(d[0]);
    for(int i=1; i<n; i++){
        h = add_to_front(d[i], h);
    }
    return h;
}



int main(){
    int data1[] = {1,2,4,5};
    int data2[] = {11,12,13,14,15};
    int size1 = sizeof(data1)/sizeof(int);
    int size2 = sizeof(data2)/sizeof(int);

    list *head1 = array_to_list(data1, size1);
    list *head2 = array_to_list(data2, size2);

        // printing list
    print_list(head1);
    printf("List length %d\n", count(head1));
    print_list(head2);
    printf("List length %d\n", count(head2));


    printf("Inserting 8 as 3rd ele of 1st list\n");
    insert(8,2,&head1);
    print_list(head1);


    printf("Replacing 3rd ele with 6 of 1st list\n");
    replace(6,2,&head1);
    print_list(head1);


    printf("Printing 4th ele of list 1 \n%d\n", list_i(head1, 3)->data);


    printf("concat both list\n");
    concat(head1, head2);
    print_list(head1);


    printf("deleting 3rd element of list 1\n");
    delete(&head1, head1->next->next);
    print_list(head1);

    printf("deleting 4th element of list 1\n");
    delete_index(&head1, 3);
    print_list(head1);

    printf("deleting value 12 from list 1\n");
    delete_val(&head1, 12);
    print_list(head1);

    printf("deleting entire list 1");
    delete_list(&head1);
    print_list(head1);

    printf("Program finished\n");
    return 0;
}