// strings are basically array of characters
// at the end of the string, c adds an additional '\0' character
// which is also considered as nul, by this c can get str length

#include <stdio.h>
#include <string.h>     // added for using string functionalities

int main(){
    char str1[20] = "Hello";
    char str2[20] = "World";
    char str3[40];

    // 1. Copy str1 into str3 using strcpy()
    strcpy(str3, str1);
    printf("str3 after copying str1: %s\n", str3);  // Outputs: Hello

    // 2. Concatenate str2 to str3 using strcat()
    strcat(str3, str2);
    printf("str3 after concatenation: %s\n", str3);  // Outputs: HelloWorld

    // 3. Find the length of str3 using strlen()
    int len = strlen(str3);
    printf("Length of str3: %d\n", len);  // Outputs: 10

    // 4. Compare str1 and str2 using strcmp()
    if (strcmp(str1, str2) == 0) {
        printf("str1 and str2 are equal.\n");
    } else {
        printf("str1 and str2 are not equal.\n");  // Outputs this, since "Hello" != "World"
    }


// other type
    char greeting[] = "Hello, World!";
        // strings can be declared like this too, here string automatically initializes its length
    printf("%s\n", greeting);  // Outputs: Hello, World!


    return 0;
}