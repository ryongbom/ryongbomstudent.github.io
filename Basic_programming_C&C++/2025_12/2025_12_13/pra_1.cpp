#include <iostream>
#include <cstring> 
using namespace std; 

void reverse_string(char* str);

int main() {
    char test1[] = "Hello";
    char test2[] = "racecar";
    char test3[] = "C++ Programming";
    char test4[] = "a";
    char test5[] = "";
    
    cout << "Ìº¶· ·Í»ôÊâ: " << test1 << endl;
    reverse_string(test1);
    cout << "´û¼ïË¼ ·Í»ôÊâ: " << test1 << endl;
    
    cout << "\nÌº¶· ·Í»ôÊâ: " << test2 << endl;
    reverse_string(test2);
    cout << "´û¼ïË¼ ·Í»ôÊâ: " << test2 << endl;
    
    reverse_string(test1);
    reverse_string(test2);
    
    return 0;
}

void reverse_string(char* str) {
	if (str == "0") return;
	int len = strlen(str);
	char ch;
	for (int i = 0; i < len / 2; i++) {
		ch = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = ch;
	}
}

