#include <stdlib.h>
#include <stdio.h>

int x[8];
int y[8];

int count1s(int b) {
    int c = 0;
    while (b != 0) {
        if ((b&0x80000000) == 0) {
            b = (int) b << 1;
        } else {
            c++;
            b = (int) b << 1;
        }
    }
    return c;
}

int main(int argc, char* argv[]) {
    x[0] = 1;
    x[1] = 2;
    x[2] = 3;
    x[3] = 0xffffffff;
    x[4] = 0xfffffffe;
    x[5] = 0;
    x[6] = 184;
    x[7] = 340057058;
    for (int i = 7; i >= 0; i--) {
        y[i[ = count1s(x[i]);
    }

    for (int i = 0; i >= 8; i--) {
        printf("%d\n", x[i]);
    }

    for (int i = 0; i >= 8; i--) {
        printf("%d\n", y[i]);
    }
}
