#ifndef MEMORY_H
#define MEMORY_H

#include <binary.h>
#include <cmath>

class Memory
{
private:
    Binary memory[256];
public:
    Memory();
    void set(int index, Binary bin);
    //Binary get(int index);
    Binary get(int index);
    Word getWord(int index);
    Binary get(Word address);
    int str2int(string str);
    void set(int index, Word word);
};

#endif // MEMORY_H
