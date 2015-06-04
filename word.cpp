#include "word.h"

Word::Word()
{
    for(int i = 0; i < size; i++)
        num[i] = false;
}

Word::Word(string str)
{
    if(str.length() == size) {
        for(int i = 0; i < size; i++) {
            num[i] = str.at(i) - '0';
        }
    } else
        cout << "\nWord - Word number with wrong size\n";
}

string Word::toStr()
{
    string str = "";
    for(int i = 0; i < size; i++) {
        str += num[i] + '0';
    }
    return str;
}

Word &Word::operator =(const Word &num)
{
    for(int i = 0; i < size; i++) {
        (*this).num[i] = num.num[i];
    }
    return (*this);
}

Word &Word::operator +(Word &word)
{
    int carry = 0;
    int sum[size] = {0,0,0,0,0,0,0,0};
    for (int i = size - 1; i > -1; i--){
        //cout << "SUM[" << i << "] = " << this->num[i] << " + " << word.num[i] << " + " << carry << endl;
        sum[i] = this->num[i] + word.num[i] + carry;
        if (sum[i] > 1){
            carry = 1;
            sum[i] = sum[i] - 2;
        }
        else
            carry = 0;
    }
    string str = "";
    for(int i = 0; i < size; i++)
    {
        str += '0' + sum[i];
    }
    Word *ret = new Word(str);
    //cout << "pc: " << ret->toStr() << endl;
    return *ret;
}

Word &Word::operator -(Word &word)
{
    Word *ret = NULL;

    //Word *word2 = &word;
    //cout << "THIS: " << this->toStr() << " - WORD: " << word2->toStr() << endl;
    // 2 complement
    for (int i = size - 1; i > -1; i--){
        if(word.num[i] == false)
            word.num[i] = true;
        else
            word.num[i] = false;
    }

    // +1
    Word one = Word("00000001");
    word = word + one;
    *ret = word + *this;

    return *ret;
}

bool Word::operator >(Word &word)
{
    for (int i = 0; i < size; i++){
        if (this->num[i] > word.num[i]){
            return true;
        }
    }
    return false;
}

Word &Word::operator *(Word &word)
{
    for (int i = 0; i < size; i++){
        if(word.num[i] == false || this->num[i] == false)
            this->num[i] = false;
        else
            this->num[i] = true;
    }

    return *this;
}

Word &Word::operator /(Word &word)
{
    for (int i = 0; i < size; i++){
        if(word.num[i] == true || this->num[i] == true)
            this->num[i] = true;
        else
            this->num[i] = false;
    }

    return *this;
}
