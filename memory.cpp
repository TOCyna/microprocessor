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
    //cout << memory[index].toStr() << endl;
}

void Memory::set(int index, Word word)
{
    Binary bin = memory[index];
    bin.setWord(word);
    memory[index] = bin;

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

Binary Memory::get(Word address)
{
    int index = str2int(address.toStr());
    Binary instruction= memory[index];
    //cout << word[7] << word[6] << word[5] << word[4] << word[3] << word[2] << word[1] << word[0] << endl;
    return instruction;
}

int Memory::str2int(string str)
{
    char aux[str.length()];
    int sum = 0;
    for (unsigned int i = 0; i < str.length(); i++){
        aux[i] = str.at(i);
        sum += (aux[i] - '0')*pow(2,str.length()-i-1);
    }
    return sum;
}

/*
bool Memory::getOp(int index)
{
    return memory[index].getOp();
}
*/
