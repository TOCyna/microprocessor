#ifndef LINE_H
#define LINE_H

#include "opcode.h"
#include "word.h"

class Line
{
private:
    OpCode op;
    Word word;
public:
    Line();
    Line get();
    OpCode getOp();
    Word getWord();
};

#endif // LINE_H
