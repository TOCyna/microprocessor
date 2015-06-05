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
    Cu cu;
    cu.run(memory);
    return 0;
}

