#include "memory.h"

Memory::Memory()
{
    for(int i = 0; i < 256; i++){ //criando memoria de 8 bits (255)
        memory[i] = Binary(); // "vazio"
    }
}

void Memory::set(int index, Binary bin)
{
    cout << "set memories" << endl;
    cout << bin.to_string() << endl;
    //Binary test = bin;
    Binary test;
    cout << test.to_string() << endl;
    test = bin;
    cout << test.to_string() << endl;
    //memory[index] = bin;
    //cout << memory[index].to_string() << endl;
}

//int Memory::get(){

//}
