#include <stdio.h>

int main() {
    int arr[3] = { 10, 20, 30 };
    int* ptr = arr;

    // 포인터를 사용하여 모든 배열 요소에 5를 더해보세요!
    // 예: 10→15, 20→25, 30→35

    for (int i = 0; i < 3; i++)
    {
        *ptr += 5;
        printf("%d", *ptr);
        ptr++;
    }

    return 0;
}
