#include "bootloader.h"

Bootloader::Bootloader()
{

}


void Bootloader::load(string address)
{
    Memory memory;
    string line;
    //load txt into reader
    ifstream reader(address.c_str());
    //iterate every txt line
    while(!reader.eof()){
        //copy one line from reader to line
        getline(reader,line);
        if (!line.empty()){
            //copy instruction in memory
            copyCode(line, memory);
            //memory.get(1).toStr();
        }
    }
}

//Save code in memory
void Bootloader::copyCode(string line, Memory &memory)
{
    //fix form
    line = fixForm(line);

    //Breaking the line into address and instruction
    string tempInstrAdress = line.substr(0, 3);
    string opCode = line.substr(3, 4);
    string word = line.substr(7, 8);
    //cout << "instrAd: " << tempInstrAdress << " opCode: " << opCode << " word: " << word << endl;

    //Converting address to int
    int instrAdress = str2int(tempInstrAdress);
    //cout << " iahsdfij: " << instrAdress << endl;
    if (instrAdress > 255){
        cout << "Error 256: stack overflow\n";
        exit(0);
    }

    //Save information (opCode + word)into memory
    Binary instr(opCode + word);
    //cout << "instru " << instr.toStr() << endl;
    memory.set(instrAdress, instr);
    //cout << "memory: " << memory.get(instrAdress).toStr() << endl;
}

//Convert the operations' names to a code
string Bootloader::name2opCode(string str)
{
    string opCode;
    if (str == "nop")
        opCode = "0000";
    else if (str == "add")
        opCode = "0001";
    else if (str == "sub")
        opCode = "0010";
    else if (str == "addi")
        opCode = "0011";
    else if (str == "and")
        opCode = "0100";
    else if (str == "or")
        opCode = "0101";
    else if (str == "movea")
        opCode = "0110";
    else if (str == "mover")
        opCode = "0111";
    else if (str == "movei")
        opCode = "1000";
    else if (str == "load")
        opCode = "1001";
    else if (str == "store")
        opCode = "1010";
    else if (str == "goto")
        opCode = "1011";
    else {
        cout << "Error 708: Invalid opCode\n";
        exit(0);
    }
    return opCode;
}


//Convert from string, in decimal form, to string, in binary form
string Bootloader::dec2bin(string str)
{
    char aux[str.length()];
    int sum = 0;
    string binary = "";

    //converting str to int
    for (int i = 0; i < str.length()-1; i++){
        aux[i] = str.at(i);
        sum =+ sum + (aux[i] - '0')*pow(10,str.length()-i-2);
    }

    if (sum > 255 || sum < 0){
        cout << "Error 100: Word can not be represented in binary\n";
        exit(0);
    }

    //converting int to bin, but reversed
    while (sum/2 != 0){
        binary.push_back(sum%2 + '0');
        sum = sum/2;
    }
    binary.push_back(sum%2 + '0');

    binary = fixSize(binary, 1);
    return binary;
}

//Convert from string to int
int Bootloader::str2int(string str)
{
    char aux[str.length()];
    int sum = 0;
    for (int i = 0; i < str.length(); i++){
        aux[i] = str.at(i);
        sum =+ sum + (aux[i] - '0')*pow(10,str.length()-i-1);
    }
    return sum;
}

//Fix the size, if necessary, to always obey our rules, mutherfucker
string Bootloader::fixSize(string str, int type)
{
    string fixed;
    if (type == 0) { //address
        if (str.length() > 3){
            cout << "Error: 303: instruction address is too damn big\n";
            exit(0);
        }
        else if (str.length() == 3)
            return str;
        else {
            for (int i = 0; i < 3 - str.length(); i++)
                fixed.push_back('0');
            for (int i = 0; i < str.length(); i++)
                fixed.push_back(str.at(i));
        }
        return fixed;
    }
    else if (type == 1){ //word
        //checking size
        if (str.length() > 8){
            cout << "Error 309: instruction is too damn big\n";
            exit(0);
        }
        //reversing string to get correct representation
        else if (str.length() == 8){
            for (int i = 0; i < str.length(); i++){
                fixed.push_back(str.at(str.length()-i-1));
            }
        }
        //reversing and puting zeros;
        else {
            for (int i = 0; i < 8 - str.length(); i++)
                fixed.push_back('0');
            for (int i = 0; i < str.length(); i++){
                fixed.push_back(str.at(str.length()-i-1));
            }
        }
        return fixed;
        cout << "fixed: " << fixed << endl;
    }
    else {
        cout << "Error 109: wrong type in function fixSize\n";
        exit(0);
    }
}

//
string Bootloader::fixForm(string line)
{
    int k = 0;
    string address = "";
    string opC = "";
    string word = "";
    while (line.at(k) != 32){
        address.push_back(line.at(k));
        k++;
    }
    k++;
    while (line.at(k) != 32){
        opC.push_back(line.at(k));
        k++;
    }
    k++;
    while (k < line.length()){
        word.push_back(line.at(k));
        k++;
    }
    address = fixSize(address,0);
    opC = name2opCode(opC);
    word = dec2bin(word);
    //cout << "adress: " << address << "\nopc: " << opC << "\nword: " << word << endl;

    return address+opC+word;
}


