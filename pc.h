#ifndef PC_H
#define PC_H

#include <word.h>

class Pc
{
private:
    Word word;
public:
    Pc();
    Word get();
    void set(Word word);
    void increment();
};

#endif // PC_H
