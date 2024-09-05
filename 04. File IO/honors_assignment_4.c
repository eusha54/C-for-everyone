/*
Open and read a file of integer pairs into an array that is created with the first integer 
telling you how many to read.  
So  4 9  11  4  5    would mean create an integer array size 4 and read into data[].   
Write a routine that places these values into a binary tree structure. 
Then walk the tree “inorder” and print these values to the screen.
*/


#include <stdio.h>
#include <stdlib.h>



// creates input file if called
FILE *create_input_file(){
    FILE *fptr = fopen("honors_assignment_4_input.txt", "w+");
    fprintf(fptr, "4 9  11  4  5");
    rewind(fptr);
    return fptr;
}


typedef int DATA;
    // initializing node structure
typedef struct node{
    DATA data;
    struct node*left;
    struct node*right;
}NODE;
    // initializing NODE pointer as BTREE
typedef NODE*BTREE;

    // prints the binary tree inorder
void inorder(BTREE root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d   ", root->data);
        inorder(root->right);
    }
}

    // initializing a node
BTREE init_node(DATA d, BTREE l, BTREE r){
    BTREE t = malloc(sizeof(NODE));
    t->data = d;
    t->left = l;
    t->right = r;
    return t;
}

    // creating tree using previously declared node function
BTREE create_tree(DATA*arr, int i, int size){
    if(i>=size) return NULL;
    else return (init_node(arr[i], create_tree(arr, 2*i+1, size),create_tree(arr, 2*i+2, size)));
}

    // converting file information into an array
void file_to_arr(FILE*fptr, DATA*arr, int n){
    for(int i=0; i<n; i++){
        fscanf(fptr,"%d", &arr[i]);
    }
}

    // printing entire array
void arr_print(DATA*arr, int n){
    for(int i=0; i<n; i++){
        printf("%d   ", arr[i]);
        if((i+1)%5==0){
            printf("\n");
        }
    }
    printf("\n");
}

int main(){
    FILE* fptr = create_input_file();

// int main(int argc, char* argv[]){
//     if(argc != 2){
//         printf("Input Error\n");
//         return 1;
//     }
//     FILE*fptr = fopen(argv[1], "r");


    int size;
    fscanf(fptr, "%d", &size);
        // scanning as the first element is list size
    DATA data[size];
        // declaring array of required size


    // reading file data into array 
    file_to_arr(fptr, data, size);
    printf("File contains following %d data\n", size);
    arr_print(data, size);

    // creating binary tree 
    BTREE root = create_tree(data, 0, size);
    printf("Walking the tree inorder\n", size);
    inorder(root);
        // printing binary tree
    
    fclose(fptr);
        // closing openned file
    return 0;
}

/*
Run the above code if any problems faced
GO to cmd and follow the following instructions
    1. go to the directory the file downloaded
          cd "folder path"
    2. type the following
          gcc assignment_file_io.c -o assignment_file_io
          ./assignment_file_io input_filename.txt
*/
