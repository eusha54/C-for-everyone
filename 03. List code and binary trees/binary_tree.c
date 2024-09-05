#include<stdio.h>
#include<stdlib.h>

typedef char DATA;
struct node{
    DATA d;
    struct node *left;
    struct node *right;
};

typedef struct node NODE;
typedef NODE *BTREE;

void inorder(BTREE root){
    if(root != NULL){
        inorder(root -> left);
        printf("%c ", root -> d);
        inorder(root -> right);
    }
}


BTREE init_node(DATA d1, BTREE p1, BTREE p2){
    BTREE t = malloc(sizeof(NODE));
        // Creating new node
    t -> d = d1;
    t -> left = p1;
    t -> right = p2;
    return t;
}

BTREE create_tree(DATA a[], int i, int size){
    if(i >= size) return NULL;
    else return (init_node(a[i], create_tree(a, 2*i+1, size), create_tree(a, 2*i+2, size)));
            // to ensure including all elements, left should be 2*i+1, and right 2*i+2
}

int main(){
    char d[] = {'a','b','c','d','e','f','g'};
    int size = sizeof(d)/sizeof(char);
    BTREE tree = create_tree(d,0,size);
    inorder(tree);
        // d b e a f c 
    return 0;
}

/*
    Actual tree
        
         a
       /   \
      b     c
    / \     / \
   d   e   f   g

   therefore output:
    dbe a fcg
   
*/