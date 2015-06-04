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
    print();
    while(true){
        getchar();
        //cout << "T1: MAR = PC" << endl;
        mar.set(pc.get());
        //cout << "MAR = " << mar.get().toStr() << endl;
        //cout << "T2: MBR = Memory / PC = PC + 1" << endl;
        mbr.set(memory.get(mar.get()));
        //cout << "MBR = " << mbr.get().toStr() << endl;
        pc.increment();
        //cout << "PC = " << pc.get().toStr() << endl;
        //cout <<  "T3: IR = MBR " << endl;
        ir.set(mbr.get());
        //cout << "IR = " << ir.get().toStr() << endl;
        //cout << "MBR: " << mbr.get().toStr() << endl;
        doIt(ir.get().getOp(), ir.get().getWord().toInt(), ir.get().getWord(), memory);
        print();
    }
}

void Cu::doIt(string str, int address, Word value, Memory memory)
{
    if (str == "0000"); // nop
    else if (str == "0001") // add
        ac.set(ula.add(ac, reg.at(address)).get());
    else if (str == "0010") // sub
        ac.set(ula.sub(ac, reg.at(address)).get());
    else if (str == "0011") // addi AC = AC + CONST
        ac.set(ula.addi(ac, value).get());
    else if (str == "0100") // and
        ac.set(ula.and_(ac, reg.at(address)).get());
    else if (str == "0101") // or
        ac.set(ula.or_(ac, reg.at(address)).get());
    else if (str == "0110") // movea
        ac.set(reg.at(address).get());
    else if (str == "0111") // mover
        reg.at(address).set(ac.get());
    else if (str == "1000") // movei
        ac.set(value);
    else if (str == "1001") // load AC = memoria[CONST]
        ac.set(memory.getWord(address));
    else if (str == "1010") // store memoria[CONST] = [AC]
        memory.set(value.toInt(), ac.get());
    else if (str == "1011") // goto
        pc.set(value);

}

void Cu::print()
{
    cout << "PC: " << pc.get().toStr() << "\nMBR: " << mbr.get().toStr()
         << "\nMAR: " << mar.get().toStr() << "\nAC: " << ac.get().toStr()
         << "\nIR: " << ir.get().toStr();
    for (int i = 0; i < 8; i++)
        cout << "\nReg" << i << ": " << reg.at(i).get().toStr();
    cout << endl;
}

void Cu::printInt()
{
    cout << "PC: " << pc.get().toInt() << "\nMBR: " << mbr.get().toStr()
         << "\nMAR: " << mar.get().toInt() << "\nAC: " << ac.get().toInt()
         << "\nIR: " << ir.get().toStr();
    for (int i = 0; i < 8; i++)
        cout << "\nReg" << i << ": " << reg.at(i).get().toInt();
    cout << endl;
}
