#include <stdlib.h>
#include <stdio.h>

void foo (char* s) {
    printf ("Hello %s\n", s);
}

int main (int argc, char** argv) {
    foo ("World");
}
