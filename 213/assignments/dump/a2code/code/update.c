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
        printf("invalid number of arguments\n");
        return -1;
    }

    for (int i=0; i<3; i++) {
        array[i] = strtol (argv[i+1], &ep, 10);
        
        if (*ep) {
            printf ("Argument is not a number\n");
            return -1;
        }
    }

    update();
     
    printf("t: %d\n", t);
    printf("array[0]: %d\n", array[0]);
    printf("array[1]: %d\n", array[1]);
    printf("array[2]: %d\n", array[2]);
    
    return 0;
    
}
