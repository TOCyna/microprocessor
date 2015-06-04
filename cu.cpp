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
        cout << "\nSEARCH: " << i+1 << endl;
        cout << "T1: MAR = PC" << endl;
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
    cout << "STR: " << str << endl;
    if (str == "0000"); // nop
    else if (str == "0001") // add
    {
        ac.set(ula.add(ac, reg.at(address)).get());
    }
//    else if (str == "0010") // sub
//    else if (str == "0011") // addi
//    else if (str == "0100") // and
//    else if (str == "0101") // or

    else if (str == "0110") // movea
    {
        ac.set(reg.at(address).get());
    }
    else if (str == "0111") // mover
    {
        reg.at(address).set(ac.get());
    }
    else if (str == "1000") // movei
    {
        cout << "AC-before = " << ac.get().toInt() << endl;
        ac.set(value);
        cout << "AC-after = " << ac.get().toInt() << endl;
    }
//    else if (str == "1001") // load
//    else if (str == "1010") // store
    else if (str == "1011") // goto
    {
        pc.set(value);
    }
//    else {
//        cout << "Error 708: Invalid opCode\n";
//        exit(0);
}
