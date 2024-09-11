// use of conditions explained

#include <stdio.h>
#include <stdbool.h>    // for booleans

int main(){
    bool condition = true;

    if(condition){
        printf("Condition was true so the code ran");
    }else if(condition ==  false){
        printf("Condition was false so this code block ran");
    }else{
        // if all the above condition is wrong this will run
    }

    return 0;
}