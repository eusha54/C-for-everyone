#include <stdio.h>
#include <stdlib.h>

// file printer, not used, but usefull while debugging
void print_file(FILE *fp){
    rewind(fp);
        // returns file pointer to the initial position
    char c;
    while((c=getc(fp))!=EOF){
        putc(c,stdout);
        // printf("%c",c);
    }
    printf("\n");
}

// array printer, not used, but usefull while debugging
void array_print(int* arr, int size){
    for(int i=0; i<size; i++){
        printf("%d   ", arr[i]);
    }
    printf("\n");
}

// creates input file if called
FILE *create_input_file(){
    FILE *fptr = fopen("assignment_file_io_input.txt", "w+");
    fprintf(fptr, "4 12 15 34 62");
    rewind(fptr);
    return fptr;
}

// returns average in double of the given int array
double average(int* arr, int size){
    double sum = 0.0;
    for(int i=0; i<size; i++){
        sum+=arr[i];
    }
    return sum/size;
}

// returns maximum num of the given int array
int maximum(int*arr, int size){
    int max=arr[0];
    for(int i=1; i<size; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}


// int main(int argc, char*argv[]){
//     if(argc!=2){
//         // checking if proper arguments are given
//         printf("Input not valid");
//     }
//     FILE*ifp = fopen(argv[1], "r");

int main(){
    FILE*ifp = create_input_file();
        // use this if you are having trouble with argv
        // and comment out above main part

    FILE*ofp = fopen("assignment_file_io_output.txt", "w+");;
        // opening and creating required files


    int size, i=0;
    fscanf(ifp, "%d", &size);
        // retriving size of required array
    int data[size];

    fprintf(ofp, "Number of items in data: %d\nGiven data is\n", size);
    printf("Number of items in data: %d\nGiven data is\n", size);
        // initial line of the output 


    while (fscanf(ifp, "%d", &data[i])!= EOF){
            // storing data from file to an array
        fprintf(ofp, "%d   ", data[i]);
        printf("%d   ", data[i]);
            // and also printing and writing on output file
        i++;
    }


    double avg = average(data, size);
    int max = maximum(data, size);
        // calculating output values
    fprintf(ofp, "\naverage :%.2f\nmaximum :%d\n", avg, max);
    printf("\naverage :%.2f\nmaximum :%d\n", avg, max);
        // printing output


    fclose(ifp);
    fclose(ofp);
        // closing both files

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