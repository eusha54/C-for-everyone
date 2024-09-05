#include <stdio.h>

int main(){
    FILE *file_ptr  = fopen("test.txt", "r");
        // fopen return pointer of the file, that's why variable type is FILE
        // arg1 = file path
        // arg2 = mode
        /*
        modes:
           "r": Open for reading. The file must exist.
           "w": Open for writing. Creates an empty file or truncates an existing file.
           "a": Open for appending. Writes data at the end of the file. Creates the file if it does not exist.
           r+": Open for reading and writing. The file must exist.
           "w+": Open for reading and writing. Creates an empty file or truncates an existing file.
           a+": Open for reading and appending. The file is created if it does not exist.
        */

    char* str[100][20];
        // assuming max 20 character per string
    int num[100];
    int i = 0;

    while(fscanf(file_ptr, "%s %d", str[i], &num[i]) != EOF){
        i++;
    }

    /*
       fscanf function returns an integer value representing the 
       number of input items successfully matched and assigned. 
       If the input ends before the first matching failure or if 
       an error occurs, EOF (End Of File) is returned
    */ 
    /*
      arg1 = file pointer
             file pointer is automatically updated to the next element
      arg2 = data type to read
      arg3,... = storage for read data
    */

    int max_size = i;

    for(i=0; i<max_size; i++){
        printf("%s - %d\n", str[i], num[i]);
    }

    fclose(file_ptr);
    return 0;
}

// test.txt
/*
    abc 1
    def 2
    ghi 3
    jkl 4
    mno 5
*/

// program output
/*
    abc - 1
    def - 2
    ghi - 3
    jkl - 4
    mno - 5
*/