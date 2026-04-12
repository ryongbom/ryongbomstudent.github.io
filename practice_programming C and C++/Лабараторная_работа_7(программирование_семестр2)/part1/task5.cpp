#include <iostream>
#include <string>

using namespace std;

string hexCharTo4Bits(char);
char fourBitsToHexChar(string);

string binaryToHex(string binary)
{
    while (binary.length() % 4 != 0)
    {
        binary = "0" + binary;
    }

    string hex_result = "";
    for (int i = 0; i < binary.length(); i += 4)
    {
        string fourBits = binary.substr(i, 4);
        hex_result += fourBitsToHexChar(fourBits);
    }
    return hex_result;
}

string hexToBinary(string hex)
{
    string result_binary = "";
    for (char ch : hex)
    {
        string str = hexCharTo4Bits(ch);
        result_binary += str;
    }
    return result_binary;
}

string hexCharTo4Bits(char hexChar)
{
    string forBitsBinary = "";
    int value = hexChar;
    if (value <= 57)
    {
        value -= 48;
    }
    else if (value > 57 && value <= 70)
    {
        value = value - 55;
    }
    else
    {
        value = value - 87;
    }

    do
    {
        int temp = value % 2;
        forBitsBinary = (char)('0' + temp) + forBitsBinary;
        value /= 2;
    } while (value);

    if (forBitsBinary.length() < 4)
    {
        while (forBitsBinary.length() < 4)
        {
            forBitsBinary = '0' + forBitsBinary;
        }
    }

    return forBitsBinary;
}

char fourBitsToHexChar(string fourBits)
{
    int result = 0;
    char result_char;
    int index = 3;
    for (char ch : fourBits)
    {
        if (ch == '1')
        {
            result += (1 << index);
        }
        index--;
    }

    if (result < 10)
    {
        result_char = result + '0';
    }
    else
    {
        result_char = result - 10 + 'A';
    }
    return result_char;
}

int main()
{
    string hex;
    string binary;

    cout << "Input hex number: ";
    cin >> hex;

    cout << "Input binary number: ";
    cin >> binary;

    string result_binary = hexToBinary(hex);
    string result_hex = binaryToHex(binary);

    cout << "result binary number: " << result_binary << endl;
    cout << "result hex number: " << result_hex << endl;

    return 0;
}

// #include <iostream>
// #include <string>
// #include <map>
// using namespace std;

// int main()
// {
//     string hex_number, bin_number(""), S3;
//     map<char, string> hex_bin{
//         {'0', "0000"}, {'1', "0001"}, {'2', "0010"}, {'3', "0011"}, {'4', "0100"}, {'5', "0101"}, {'6', "0110"}, {'7', "1000"}, {'8', "1000"}, {'9', "1001"}, {'A', "1010"}, {'B', "1011"}, {'C', "1100"}, {'D', "1101"}, {'E', "1110"}, {'F', "1111"}};

//     cin >> hex_number;
//     if (hex_number == "0")
//         bin_number = "0";
//     else
//     {
//         for (int i = 0; i < hex_number.length(); i++)
//         {
//             bin_number += hex_bin[hex_number[i]];
//         }
//     }
//     while (bin_number[0] == '0')
//     {
//         bin_number.erase(bin_number.begin());
//     }
//     cout << bin_number << endl;

//     return 0;
// }