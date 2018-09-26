#include "stdio.h"

int a;
int b;
int c[4];

void foo() {
    b = a + 5;
    c[0] = ~(a + c[b]);
}

int main (int argc, char* argv[]) {
    
    printf( "enter a int value for a in range[-5,-2]: " );
    scanf( "%d", &a );
    // what will happen if the user enters a number outside [-5,-2]?
    // what might be a way to prevent the user from doing this?
    
    for (int i=0; i<4; i++) {
        printf( "enter a int value for c[%d]: ", i );
        scanf( "%d", &c[i] );
    }
    foo();
    
    printf("a: %d, b: %d\n", a, b);
    
    for (int i=0; i<4; i++)
      printf("c[%d]: %d\n", i, c[i]);
    
    return 0;
}
