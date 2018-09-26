#include "stdio.h"

int a;
int b;
int c[8];
int *d = c;

void foo() {
    
    c[b] = ((c[a] + 1) >> 15) - 1;
    b = b + 4;
    d[b] = d[a] - 4;
    
    
}

int main (int argc, char* argv[]) {
    
    printf( "enter a int value for a in range[0,7]: " );
    scanf( "%d", &a );
    printf( "enter a int value for b in range[0,7]: " );
    scanf( "%d", &b );
    
    // what will happen if the user enters a number outside [0,7]?
    // what might be a way to prevent the user from doing this?
    
    for (int i=0; i<8; i++) {
        printf( "enter a int value for c[%d]: ", i );
        scanf( "%d", &c[i] );
    }
    
    foo();
    
    printf("a: %d, b: %d\n", a, b);
    
    for (int i=0; i<6; i++) {
        // the number in to format specifier (ie. %10d) specifies
        // the width of the field the variable will print in
        // try removing it to see the difference.
        printf("c[%d]: %10d, d[%d]: %10d \n", i, c[i], i, d[i]);
    }
    
    return 0;
    
}