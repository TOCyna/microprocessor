#include "memory.h"

Memory::Memory()
{
    for(int i = 0; i < 256; i++){ //criando memoria de 8 bits (255)
        memory[i] = Binary(); // "vazio"
    }
}

void Memory::set(int index, Binary bin)
{
    memory[index] = Binary(bin.to_string());
}

//int Memory::get(){

//}
