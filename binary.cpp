#include "binary.h"

Binary::Binary()
{
    for(int i = 0; i < size; i++)
        num[i] = false;
}

Binary::Binary(string str)
{
    if(str.size() == size) {
        for(int i = 0; i < size; i++) {
            num[i] = str.at(i) - '0';
        }
    } else
        cout << "\nBINARY - binary number with wrong size\n";
}

string Binary::to_string()
{
    string str = "";
    for(int i = 0; i < size; i++) {
        str += num[i] + '0';
    }
    return str;
}
