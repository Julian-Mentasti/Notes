#include "stdio.h"
#include "stdlib.h"


int t;
int array[3];

void update() {
    t = array[2];
    t += 4;
    array[1] = array[2] + t;
    array[0] = t;
}


int main (int argc, char* argv[]) {
    char* ep;
    
    if (argc != 4) {
        printf("invalid number of arguments, takes 1 number\n");
        return -1;
    }
    
    array[0] = strtol (argv[1], &ep, 10);
    if (*ep) {
        printf ("Argument is not a number\n");
        return -1;
    }
    array[1] = strtol (argv[2], &ep, 10);
    if (*ep) {
        printf ("Argument is not a number\n");
        return -1;
    }
    array[2] = strtol (argv[3], &ep, 10);
    if (*ep) {
        printf ("Argument is not a number\n");
        return -1;
    }
    
    update();
    
    printf("t: %d\narray[0]: %d\narray[1]: %d\narray[2]: %d\n", t, array[0], array[1], array[2]);
    
    return 0;
    
}
