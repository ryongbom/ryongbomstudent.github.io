#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

char result[100] = {};
bool used[100] = {false};

void printWord(string st, int i)
{
    if (i == st.length())
    {
        for (int j = 0; j < i; j++)
        {
            cout << result[j];
        }
        cout << endl;
        return;
    }

    for (int k = 0; k < st.length(); k++)
    {
        if (used[k])
            continue;

        used[k] = true;
        result[i] = st[k];

        printWord(st, i + 1);
        used[k] = false;
    }
}

int main()
{
    set<char> setChar;
    string second = "";
    string first = "";
    cout << "Input string: ";
    getline(cin, first);

    for (char ch : first)
    {
        if (isalpha(ch))
        {
            setChar.insert(tolower(ch));
        }
    }

    for (char ch : setChar)
    {
        second.push_back(ch);
    }

    printWord(second, 0);

    return 0;
}