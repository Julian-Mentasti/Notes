#include "stdio.h"

int a[4];
int b[4];
int c[4];
int d;

void foo() {
    
    d = d + (a[d & 3] & b[(d+1) & 3]) + ~c[(d+2) & 3];
    a[0] = b[1] >> 2;
    b[1] = c[2] << 2;
    c[d & 3] = a[(d+1) & 3];
    
}

int main (int argc, char* argv[]) {
    
    printf( "enter a int value for d: " );
    scanf( "%d", &d );
    
    for (int i=0; i<4; i++) {
        printf( "enter a int value for a[%d]: ", i );
        scanf( "%d", &a[i] );
    }
    
    for (int i=0; i<4; i++) {
        printf( "enter a int value for b[%d]: ", i );
        scanf( "%d", &b[i] );
    }
    
    for (int i=0; i<4; i++) {
        printf( "enter a int value for c[%d]: ", i );
        scanf( "%d", &c[i] );
    }
    
    foo();
    
    printf("d: %d\n", d);
    
    for (int i=0; i<4; i++)
    printf("a[%d]: %d\n", i, a[i]);
    
    for (int i=0; i<4; i++)
    printf("b[%d]: %d\n", i, b[i]);
    
    for (int i=0; i<4; i++)
    printf("c[%d]: %d\n", i, c[i]);

    return 0;
    
}