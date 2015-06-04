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

Word Binary::getWord()
{
    string str = "";
    for (int i = 0; i < 8; i++){
        str += num[i+4] + '0';
    }
    //cout << "String desgracada: " << str << endl;
    Word value = Word(str);
    return value;
}

string Binary::getOp()
{
    string str = "";
    for (int i = 0; i < 4; i++){
        str += num[i] + '0';
    }
    return str;
}

void Binary::setWord(Word word)
{
    string str = word.toStr();
    cout << "STR: " << str << endl;
    for (int i = 0; i < 8; i++){
        num[i+4] = str.at(i) - '0';
    }
}
