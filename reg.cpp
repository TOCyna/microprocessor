#include "reg.h"

Reg::Reg()
{

}

Word Reg::get()
{
    return word;
}

void Reg::set(Word word)
{
    this->word = word;
}
