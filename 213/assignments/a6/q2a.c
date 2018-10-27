#include <stdlib.h>
#include <stdio.h>

int* x;
void store (int a, int b) {
    x[b] += a;
}

int main (int argc, char* argv[]) {
    x = malloc(10 * sizeof(int));
    int a = 1;
    int b = 2;
    store(3,4);
    store(a,b);
    for (int i=0; i<10; i++){
        printf("%d\n",x[i]);
    }
}
