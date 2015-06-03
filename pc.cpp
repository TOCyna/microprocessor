#include "pc.h"

Pc::Pc()
{
    word = Word("00000000");
    //cout << "TEST PC WORD: " << word.toStr() << endl;
}

Word Pc::get()
{
    return word;
}

void Pc::set(Word word)
{
    this->word = word;
}

void Pc::increment(void)
{
    Word one = Word("00000001");
    word = word + one;
}
