#include "ula.h"

ULA::ULA()
{
}

Reg ULA::add(Reg ac, Reg reg)
{
    Reg sum;
    Word word1 = ac.get();
    Word word2 = reg.get();
    sum.set(word1+word2);
    return sum;
}

Reg ULA::sub(Reg ac, Reg reg)
{
    Reg sum;
    Word word1 = ac.get();
    Word word2 = reg.get();
    sum.set(word1-word2);
    return sum;
}

/*


void ULA::addi(bool n1[], bool n2[])
{
    bool addi[size] = add(n1[],n2[]);
    ac = ac + addi;
}

void ULA::and_(bool n1[], bool n2[])
{
    bool and[size];
    for (int i = 0; i < size; i++){
        if (n1[i] == 0 || n2[i] == 0)
            and[i] = 0;
    }
}

void ULA::or_()
{

}

bool & ULA::addAux(bool n1, bool n2)
{
    int carry = 0;
    int sum[size];
    for (int i = size - 1; i > -1; i--){
        sum[i] = n1[i] + n2[i] + carry;
        if (sum[i] > 1){
            carry = 1;
            sum[i] = sum[i] - 2;
        }
        else
            carry = 0;
    }
    return &sum;
}

bool ULA::twosComplement(bool n[])
{
    bool n1[size] = {0,0,0,0,0,0,0,1};
    bool n[size] = num.getValue(index);
    for (int i = 0; i < size; i++){
        if (n[i] == 0)
            n[i] = 1;
        else
            n[i] = 0;
    }
    n = addAux(n,n1);
}
*/
