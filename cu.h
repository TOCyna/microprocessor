#ifndef CU_H
#define CU_H

#include <ula.h>
#include <reg.h>
#include <regi.h>
#include <memory.h>
#include <pc.h>
#include <array>

class Cu
{
private:
    ULA ula;
    Pc pc;
    Regi mbr;
    Regi ir;
    Reg mar;
    Reg ac;
    array<Reg,8> reg;
public:
    Cu();
    void run(Memory memory);
    void doIt(string str, int address, Word value);
};

#endif // CU_H
