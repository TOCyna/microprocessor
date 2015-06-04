#ifndef WORD_H
#define WORD_H

#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Word
{
private:
    static const int size = 8;
    bool num[size];
public:
    Word();
    Word(string str);
    string toStr();
    int toInt(void);
    Word &operator =(const Word &num);
    Word &operator +(Word &word);
    Word &operator -(Word &word);
    bool operator >(Word &word);
    Word &operator *(Word &word);
    Word &operator /(Word &word);
};

#endif // WORD_H
