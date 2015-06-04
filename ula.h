#ifndef ULA_H
#define ULA_H

#include "reg.h"

using namespace std;

class ULA
{
private:

public:
    ULA();
    Reg add(Reg ac, Reg reg);
    /*void sub(bool n1[], bool n2[]);
    void addi(bool n1[], bool n2[]);
    void and_(bool n1[], bool n2[]);
    void or_(bool n1[], bool n2[]);
    bool twosComplement(bool n[]);
    bool &addAux(bool &n1, bool &n2);*/
    Reg sub(Reg ac, Reg reg);
    Reg addi(Reg ac, Word word);
    Reg and_(Reg ac, Reg reg);
    Reg or_(Reg ac, Reg reg);
};

#endif // ULA_H
