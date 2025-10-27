#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    
    printf("교환 전: x=%d, y=%d\n", x, y);
    swap(&x, &y);
    printf("교환 후: x=%d, y=%d\n", x, y);
    
    return 0;
}
