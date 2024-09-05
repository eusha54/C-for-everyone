#include <stdio.h>
#define MAX_HW 20

// input file creating in case lost
FILE *create_input_file(){
    FILE *fptr = fopen("advanced_file_io_input.txt", "w+");
    fprintf(fptr, "10           20 \n40 \n\n\n50 60");
    rewind(fptr);
    return fptr;
}


// reading text file data and storing into array
void read_data(FILE *ptr, int d[], int *size){
    *size = 0;
    rewind(ptr);
    while(fscanf(ptr, "%d", &d[*size]) != EOF){
        (*size)++;
    }
}

// array printer
void print_array(int d[], int size){
    int i;
    for(i=0; i<size; i++){
        printf("%d\t", d[i]);
        if((i+1)%10 == 0) printf("\n");
    }
}

// average from an array of int
double average(int d[], int size){
    int i;
    double avg = 0.0;
    for(i=0; i<size; i++) avg+=d[i];
    return (avg/size);
}

int main(){
    int i, size = MAX_HW;
    FILE *ifp;
    int data[MAX_HW];

    ifp = fopen("advanced_file_io_input.txt", "r");
    // ifp = create_input_file();
    read_data(ifp, data, &size);
        // reading input files into arrays

    printf("%d numbers of the file are\n", size);
    print_array(data, size);
    printf("\nAverage Score is:\n%.2f\n", average(data, size));
    
    fclose(ifp);
    return 0;
}
 
/*
advanced_file_io_input.txt:
10           20 
40 


50 60

program output:
10	20	40	50	60	
*/