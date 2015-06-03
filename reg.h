#ifndef Reg_H
#define Reg_H

#include "word.h"

class Reg
{
private:
    Word word;
public:
    Reg();
    Word get();
    void set(Word word);
};

#endif // Reg_H
