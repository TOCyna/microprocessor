#include "regi.h"

Regi::Regi()
{
}

Binary Regi::get()
{
    return instruction;
}

void Regi::set(Binary instruction)
{
    this->instruction = instruction;
}
