#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    
    cout << "·Í½£ 1: ¹ÉÊâ ÊıºÏ ¾¥µÙ" << endl;
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "\n·Í½£ 2: ¹ÉÊâ ÊıºÏ 2¹Éµá ¶í´É±¨" << endl;
    for(int i = 0; i < 5; i++) {
        arr[i] = arr[i] * 2;
    }

    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cout << "\n·Í½£ 3: 2½ÓÌº ¹ÉÊâ (3x3)" << endl;
    int matrix[3][3] = {{1, 2, 3}, 
                        {4, 5, 6}, 
                        {7, 8, 9}};
    
    int diagonal_sum = 0;
    for(int i = 0; i < 3; i++) {
        diagonal_sum += matrix[i][i];
    }
    cout << "´İ°¢ºº Âİ: " << diagonal_sum << endl;
    
    return 0;
}
