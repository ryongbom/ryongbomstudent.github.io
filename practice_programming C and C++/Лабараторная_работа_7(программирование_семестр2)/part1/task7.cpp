#include <iostream>
#include <string>
using namespace std;

int main()
{
    int len;
    cout << "Input length of binary: ";
    cin >> len;

    //    int max_number = 1;
    //    int temp = len - 1;
    //    while (temp)
    //    {
    //        max_number = max_number * 2 + 1;
    //        temp--;
    //    }

    int max_number = (1 << len) - 1;

    cout << "result binaries which length " << len << " : ";
    for (int num = 0; num <= max_number; num++)
    {
        string result_binary = "";
        for (int i = len - 1; i >= 0; i--)
        {
            int sub_res = (num >> i) & 1;

            result_binary += (sub_res) ? '1' : '0';
        }
        cout << result_binary << " ";
    }
    cout << endl;
}