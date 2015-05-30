#ifndef BINARY_H
#define BINARY_H

#include <iostream>
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
    string to_string();
    Binary &operator =(Binary &num);
};

#endif // BINARY_H
