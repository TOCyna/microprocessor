/*======Simulador de Micro-Processador 8  Bits======
 * UFRN 2015.1
 * Trabalho de Arquitetura de computadores
 * Professor Dr. Diego Pedrosa
 * Culpados:
 * Álvaro Negreiros
 * Hanoch Griner
 * Taynara Pinheiro
 */

#include <bootloader.h>
#include <pc.h>
#include <reg.h>
#include <ula.h>
#include <cu.h>
#include <array>


int main()
{
    Bootloader * boot = new Bootloader();
    //  Binary bin("101010101010");
    Memory memory;
    boot->load("/opt/temp/assembly.txt", memory);
    //cout << "Test memory: " << memory.get(1).toStr() << endl;
    //Memory *memory = new Memory;
    //memory->set(10,bin);
    //cout << memory->get(100).toStr() << endl;
    //cout << "Test get Word " << memory.getWord(3).toStr() << endl;
    Pc pc = Pc();
    //cout << "Word: " << pc.get().toStr() << endl;
    for (int i = 0; i < 10; i++)
        pc.increment();
    Reg reg1, reg2;
    reg1.set(Word("00000111"));
    reg2.set(Word("11100000"));
    //Word word = Word("00000101");
    //cout << regs.get().toStr() << endl;
    ULA ula;
    //reg1.set(ula.add(reg1,reg2).get());
    //cout << "ADD TEST: " << reg1.get().toStr() << endl;
    //reg1.set(ula.sub(reg1,reg2).get());
    //cout << "SUB TEST: " << reg1.get().toStr() << endl;
    //reg1.set(ula.addi(reg1,word).get());
    //cout << "ADDI TEST: " << reg1.get().toStr() << endl;
    //reg1.set(ula.and_(reg1,reg2).get());
    //cout << "AND TEST: " << reg1.get().toStr() << endl;
    //reg1.set(ula.or_(reg1,reg2).get());
    //cout << "OR TEST: " << reg1.get().toStr() << endl;
    Cu cu;
    cu.run(memory);
    //Memory memory1;
    //Word word = Word("00001111");
    //memory1.set(0, word);
    //cout << memory1.get(0).toStr();
    cout << "=== END MAIN ===\n" ;
    return 0;
}

