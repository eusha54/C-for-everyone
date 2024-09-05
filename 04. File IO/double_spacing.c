#include <stdio.h>
#include <string.h>     // for file operations

/*
fp = file pointer
ifp = input fp
ofp = output fp
ifn = if name
ofn = of name
*/


// prints entire file
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

// overwrites previous file with given str
void file_write(FILE *fp, char* str){
    int i;
    int size = strlen(str);
        // get size of a string
    rewind(fp);
    for(i=0; i<size; i++){
        putc(str[i], fp);
            // writes file 
    }
}

void double_space(FILE *ifp, FILE *ofp){
        // doubling each space of a file
    rewind(ifp);
    rewind(ofp);
    char c;
    while((c=getc(ifp))!=EOF){
        putc(c, ofp);
        if(c==' '){
            putc(c, ofp);
        }
    }
}

int main(){
    FILE *ifp, *ofp;
    char* ifn = "double_spacing_input.txt";
    char* ofn = "double_spacing_output.txt";
        // input and output file names

    char* str = "hello this is a sample text";
        // text to be written on input file

    ifp = fopen(ifn,"w+");
    ofp = fopen(ofn,"w+");
    
    file_write(ifp, str);
    print_file(ifp);
        // writing the input file and printing
    
    double_space(ifp,ofp);
    print_file(ofp);
        // double spacing the of and printing

    fclose(ifp);
    fclose(ofp);
        // closing both file

    return 0;
}

/*
hello this is a sample text
hello  this  is  a  sample  text
*/