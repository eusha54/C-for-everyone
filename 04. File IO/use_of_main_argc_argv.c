#include <stdio.h>

int main(int argc,char* argv[]){
    /*
        argc = argument count
        argv = argument values
    */

    // for two file inputs, argc should equal to 3
    // first value is the program file itself
    // checking this
    if(argc != 3){
        printf("argument not fulfilled properly");
        return 1;
    }

    FILE *fptr1 = argv[1];
        // first input file
    FILE *fptr2 = argv[2];
        // second input file

    /*
        all file operations here
    */

    fclose(fptr1);   
    fclose(fptr2);   
        // closing all files

    return 0;
}

/*
    Run file
        1. CD to directory
            cd "directory path"
        2. Compile code
            gcc use_of_main_argc_argv.c -o use_of_main_argc_argv
        3. Run code with arguments
            ./use_of_main_argc_argv input1.txt input2.txt
*/