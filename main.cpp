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

int main()
{
    Bootloader boot = Bootloader();
    //  Binary bin("101010101010");
    boot.load("/opt/temp/assembly.txt");
    //Memory *memory = new Memory;
    //memory->set(10,bin);
    //cout << memory->get(100).toStr() << endl;
    return 0;
}

