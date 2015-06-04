#ifndef BINARY_H
#define BINARY_H

#include <iostream>
#include <string>
#include <word.h>
#include <string>


using namespace std;
class Binary
{
private:
    static const int size = 12;
    bool num[size];
public:
    Binary();
    Binary(string str);
    string toStr();
    Binary &operator =(const Binary &num);
    Word getWord();
    string getOp();
};

#endif // BINARY_H
