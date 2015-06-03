#include "binary.h"

Binary::Binary()
{
    for(int i = 0; i < size; i++)
        num[i] = false;
}

Binary::Binary(string str)
{
    if(str.length() == size) {
        for(int i = 0; i < size; i++) {
            num[i] = str.at(i) - '0';
        }
    } else
        cout << "\nBinary - Binary number with wrong size\n";
}

string Binary::toStr()
{
    string str = "";
    for(int i = 0; i < size; i++) {
        str += num[i] + '0';
    }
    return str;
}

Binary& Binary::operator =(const Binary& num)
{
    for(int i = 0; i < size; i++) {
        (*this).num[i] = num.num[i];
    }
    return (*this);
}

bool Binary::getValue()
{
    bool value[8];
    for (int i = 0; i < 8; i++){
        value[i] = num[i+4];
    }
    return value;
}

bool Binary::getOp()
{
    bool op[4];
    for (int i = 0; i < 4; i++){
        op[i] = num[i];
    }
    return op;
}
