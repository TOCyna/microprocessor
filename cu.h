#ifndef CU_H
#define CU_H

#include <ula.h>
#include <reg.h>
#include <regi.h>
#include <memory.h>
#include <pc.h>
#include <array>
#include <stdlib.h>
#include <stdio.h>

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
    void doIt(string str, int address, Word value, Memory memory);
    void print();
    void printInt();
};

#endif // CU_H
