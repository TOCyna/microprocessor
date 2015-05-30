#include "bootloader.h"

Bootloader::Bootloader()
{
    cout << "\n Bootloader Created \n";
    Memory memory;
    memory.set(2,Binary("100000000000"));

}

void Bootloader::load(string address)
{
    string line;
    ifstream reader(address.c_str()); //carregando txt em aux
    while(!reader.eof()){ // itera linha por linha o txt
        getline(reader,line); //pega uma linha de aux e coloca em line
        //if (!line.empty()){
        //    //cout<<"\n line: "<<line<<endl;
        //    bootloader.get_intrucao(line, &elefante); // armazena a instrucao na memoria
        //}
    }
}
