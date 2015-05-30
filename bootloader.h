#ifndef BOOTLOADER_H
#define BOOTLOADER_H

#include <iostream>
#include <string>
#include <fstream>
#include <memory.h>

using namespace std;

class Bootloader
{
public:
    Bootloader();
    void load(string address);
};

#endif // BOOTLOADER_H
