#include "memory.h"

Memory::Memory()
{
    for(int i = 0; i < 256; i++){ //8 bits memory (256 positions)
        memory[i] = Binary(); // "empty"
    }
}

void Memory::set(int index, Binary bin)
{
    //cout << "Binary: " << bin.toStr() << endl;
    memory[index] = bin;
    cout << memory[index].toStr() << endl;
}

Binary Memory::get(int index)
{
    return memory[index];
}

bool Memory::getValue(int index)
{
    return memory[index].getValue();
}

bool Memory::getOp(int index)
{
    return memory[index].getOp();
}
