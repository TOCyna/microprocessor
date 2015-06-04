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

Word Memory::getWord(int index)
{
    Word word;
    word = memory[index].getWord();
    //cout << word[7] << word[6] << word[5] << word[4] << word[3] << word[2] << word[1] << word[0] << endl;
    return word;
}

/*
bool Memory::getOp(int index)
{
    return memory[index].getOp();
}
*/
