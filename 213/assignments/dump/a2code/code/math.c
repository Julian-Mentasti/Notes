#include "stdio.h"
#include "stdlib.h"

int a;
int b;

void math () {
    a = (((b+1) + b / 2) & b) << 2;
    // use printf to print intermediary results
    // to help you understand the program.
    // Examples (uncomment to use):
    //printf("(b+1) is: %d\n", (b+1));
    //printf("((b+1) + b / 2)  is: %d\n", ((b+1) + b / 2));
}

int main (int argc, char* argv[]) {
    char* ep;
    
    if (argc != 2) {
        printf("invalid number of arguments\n");
        return -1;
    }
    
    b = strtol (argv[1], &ep, 10);
    
    if (*ep) {
        printf ("Argument is not a number\n");
        return -1;
    }
    
    printf("a: %d, b: %d\n", a, b);
    
    math();
    
    printf("a: %d, b: %d\n", a, b);
    
    return 0;
    
}
