#ifndef BOOTLOADER_H
#define BOOTLOADER_H

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include "memory.h"
#include "binary.h"

using namespace std;

class Bootloader
{
public:
    Bootloader();
    void load(string address, Memory &memory);
    string name2opCode(string str);
    //string dec2bin(string str);
    void copyCode(string line, Memory &memory);
    int str2int(string str);
    string dec2bin(string str);
    string fixSize(string str, int type);
    string fixForm(string line);
};

#endif // BOOTLOADER_H
