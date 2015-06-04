#include "ula.h"

ULA::ULA()
{
}

Reg ULA::add(Reg ac, Reg reg)
{
    Reg sum;
    Word wAc = ac.get();
    Word wReg = reg.get();
    sum.set(wAc+wReg);
    return sum;
}

Reg ULA::sub(Reg ac, Reg reg)
{
    Reg sum;
    Word wAc = ac.get();
    Word wReg = reg.get();
    sum.set(wAc-wReg);
    return sum;
}

Reg ULA::addi(Reg ac, Word word)
{
    Reg sum;
    Word wAc = ac.get();
    sum.set(wAc + word);
    return sum;
}

Reg ULA::and_(Reg ac, Reg reg)
{
    Reg and0;
    Word wAc = ac.get();
    Word wReg = reg.get();
    and0.set(wAc*wReg);
    return and0;
}

Reg ULA::or_(Reg ac, Reg reg)
{
    Reg or0;
    Word wAc = ac.get();
    Word wReg = reg.get();
    or0.set(wAc/wReg);
    return or0;
}
