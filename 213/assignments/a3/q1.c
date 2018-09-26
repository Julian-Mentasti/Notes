#include <stdlib.h>
#include <stdio.h>

// YOU: Allocate these global variables, using these names
//      when converting to assembly
int  i,j;
int* p;
int  a[10];

int main (int argc, char* argv[]) {
    char* ep;
    
    // Ignore this block of code when converting to assembly
    if (argc != 11) {
        fprintf (stderr, "usage: a[0] ... a[9]\n");
        exit (EXIT_FAILURE);
    }
    
    for (int k=0; k<10; k++) {
        a[k] = strtol (argv[k+1], &ep, 10);
        if (*ep) {
            fprintf (stderr, "Argument is not a number\n");
            exit (EXIT_FAILURE);
        }
    }
    
    // YOU: Implement this code when converting to assembly
    j  = 3;
    i  = a[j];
    i  = i & 9;
    i  = a[i];
    p  = &j;
    j++;
    *p = *p - 2;
    p  = &a[a[j]];
    *p = *p + a[4];
    
    // Ignore this block of code when converting to assembly
    printf ("i=%d j=%d a={", i, j);
    for (int k=0; k<10; k++)
        printf("%d%s ", a[k], k<9? ",": "}\n");
    
    // in the printf above, what does this do: k<9? ",": "}\n"
}

