#ifndef MEMORY_H
#define MEMORY_H

#include <binary.h>

class Memory
{
private:
    Binary memory[256];
public:
    Memory();
    void set(int index, Binary bin);
    Binary get(int index);
};

#endif // MEMORY_H
