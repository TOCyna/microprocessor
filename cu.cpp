#include "cu.h"

Cu::Cu()
{
    ula = ULA();
    pc = Pc();
    mbr = Regi();
    ir = Regi();
    mar = Reg();
    ac = Reg();
    for (int i=0; i<8; i++) reg.at(i) = Reg();
}

void Cu::run(Memory memory)
{
    for (int i = 0; i < 14; i++){
        cout << "SEARCH: " << i+1 << endl;
        cout << " T1: MAR = PC" << endl;
        mar.set(pc.get());
        cout << "MAR = " << mar.get().toStr() << endl;

        cout << "T2: MBR = Memory / PC = PC + 1" << endl;
        mbr.set(memory.get(mar.get()));
        cout << "MBR = " << mbr.get().toStr() << endl;
        pc.increment();
        cout << "PC = " << pc.get().toStr() << endl;
        cout <<  "T3: IR = MBR " << endl;
        ir.set(mbr.get());
        cout << "IR = " << ir.get().toStr() << endl;
        //cout << "MBR: " << mbr.get().toStr() << endl;
        doIt(ir.get().getOp(), ir.get().getWord().toInt(), ir.get().getWord());
        cout << "PC: " << pc.get().toInt() << " MBR: " << mbr.get().toStr()
             << " MAR: " << mar.get().toInt() << " AC: " << ac.get().toInt()
             << " IR: " << ir.get().toStr() << endl;
    }

    /*/RUN
    //T1: MAR ← (IR(endereço))
    mar.set(ir.get().getWord());
    //T2: MBR ← Memória
    mbr.set(memory.get(mar.get()));
    //T3: R1 ← (R1) + (MBR)
    */
}

void Cu::doIt(string str, int address, Word value)
{
    if (str == "nop");
    else if (str == "add")
        ac.set(ula.add(ac, reg.at(address)).get());
    //else if (str == "sub")
    //    opCode = "0010";
   // else if (str == "addi")
    //    opCode = "0011";
    //else if (str == "and")

    //else if (str == "or")

    else if (str == "movea")
        ac.set(reg.at(address).get());
    else if (str == "mover")
        reg.at(address).set(ac.get());
    else if (str == "movei")
        ac.set(value);
//    else if (str == "load")
//        opCode = "1001";
//    else if (str == "store")
//        opCode = "1010";
    else if (str == "goto")
        pc.set(value);
//    else {
//        cout << "Error 708: Invalid opCode\n";
//        exit(0);
}



