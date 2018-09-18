#include "stdio.h"
#include "stdlib.h"

int sum;
int and;
int b[2];

void foo () {
    sum = b[0] + b[1];
    and = b[0] & b[1];
}


int main (int argc, char* argv[]) {
    char* ep;
    
    if (argc != 3) {
        printf("invalid number of arguments, takes 2 numbers\n");
        return -1;
    }
    
    for (int i=0; i<2; i++) {
        b[i] = strtol (argv[i+1], &ep, 10);
        if (*ep) {
            printf ("Argument is not a number\n");
            return -1;
        }
    }
    
    printf("b[0]: %d b[1]: %d\n\n", b[0], b[1]);
    
    foo();
    
    printf("sum: %d, and: %d\n", sum, and);
    
    return 0;
    
}
