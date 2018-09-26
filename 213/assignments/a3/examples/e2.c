#include "stdio.h"

int a;
int b[4];
int c;
int d[8];

void foo() {
    
    c = b[0] + ((d[a & 7] + b[c & 3]) & 42) + 1;
}

int main (int argc, char* argv[]) {
    
    printf( "enter a int value for a: " );
    scanf( "%d", &a );
    printf( "enter a int value for c: " );
    scanf( "%d", &c );
    
    for (int i=0; i<4; i++) {
        printf( "enter a int value for b[%d]: ", i );
        scanf( "%d", &b[i] );
    }
    
    for (int i=0; i<8; i++) {
        printf( "enter a int value for d[%d]: ", i );
        scanf( "%d", &d[i] );
    }
    
    foo();
    printf("a: %d, c: %d\n", a, c);
    
    for (int i=0; i<4; i++)
    printf("b[%d]: %d\n", i, b[i]);
    
    for (int i=0; i<8; i++)
    printf("d[%d]: %d\n", i, d[i]);
    
    return 0;
    
}