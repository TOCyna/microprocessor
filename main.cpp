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
    boot.load("/home/alvaro/Documentos/MicroProcessador/MicroProcessador/assembly.txt");
    cout << true + true;
    cout << "Hello World!" << endl;
    return 0;
}

