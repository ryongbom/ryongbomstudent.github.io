#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
#include <locale>

using namespace std;

int main()
{
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "russian");
    
    string st;
    cout << "Input sentence, with which you want to work: ";
    getline(cin, st);
    
//    unordered_set<char> vowels = {'а', 'е', 'и', 'о', 'у', 'ы', 'э', 'ю', 'я'};
	unordered_set<char> vowels;
    vowels.insert(0xE0); // а
    vowels.insert(0xE5); // е
    vowels.insert(0xE8); // и
    vowels.insert(0xEE); // о
    vowels.insert(0xF3); // у
    vowels.insert(0xFB); // ы
    vowels.insert(0xFD); // э
    vowels.insert(0xFE); // ю
    vowels.insert(0xFF); // я
    unordered_set<char> findVowels;
    
    for (char ch : st) {
    	if (ch != ',' && ch != ' ' && ch != '.') {
    		if (vowels.find(ch) != vowels.end()) {
    			findVowels.insert(ch);
			}
		}
	}
	
	vector<char> sortedVowels(findVowels.begin(), findVowels.end());
	sort(sortedVowels.begin(), sortedVowels.end());
	
	cout << "result: ";
	if (sortedVowels.empty()) {
		cout << "(none)";
	} else {
		for (char c : findVowels) {
			cout << c << " ";
		}
		cout << endl;
	}
	
	return 0;
}