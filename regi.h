#ifndef Regi_H
#define Regi_H

#include <binary.h>

class Regi
{
private:
    Binary instruction;
public:
    Regi();
    Binary get();
    void set(Binary instruction);
};

#endif // Regi_H
