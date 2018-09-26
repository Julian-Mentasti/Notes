#include <stdlib.h>
#include <stdio.h>

// YOU: Allocate these global variables, using these names
int  a[3];
int* s;
int  tos;
int  tmp;

int main (int argv, char** argc) {
    // Ignore this block of code
    if (argv != 6) {
        fprintf (stderr, "usage: a b c d e\n");
        exit (EXIT_FAILURE);
    }
    s = malloc(5 * sizeof(int));
    for (int k=0; k<3; k++)
      a[k] = 0;
    for (int k=0; k<5; k++)
    s[k] = atol (argc[1 + k]);
    
    // YOU: Implement this code
    tmp = 0;
    tos = 0;
    a[0] = s[tos] + tos;
    tos++;
    a[1] = s[tos] + tos;
    tos++;
    a[2] = s[tos] + tos;
    tos++;
    tos--;
    tmp = a[tos];
    tos--;
    tmp = tmp + a[tos];
    tos--;
    tmp = tmp + a[tos];
    s[0] = tmp;

    
    // Ignore this block of code
    printf ("a[0]=%d a[1]=%d a[2]=%d\n", a[0],a[1],a[2]);
    printf ("tos=%d tmp=%d \n", tos, tmp);
    for (int k=0; k<5; k++)
    printf("s[%d]=%d, ",k,s[k]);
    printf("\n");
}