#include <stdio.h>
#define ADD(x) x+x
#define SUB(x) x-x

int main() {
    int y = ADD(3) / SUB(3); // int y = 3+3/3-3 = 1
    printf("%d", ADD(y));    // 1+1 = 2
}