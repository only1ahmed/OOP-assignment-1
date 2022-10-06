#include "A1_P1_A_20210046_20210508_20210524.h"
using namespace std;

bool BigDecimalInt:: operator== (BigDecimalInt anotherDec){
    if ((*this).number.size() != anotherDec.number.size() ){
        return false;
    }
    for (auto i = 0;i < number.size();i++){
        if ((*this).number[i] != anotherDec.number[i]){
            return false;
        }
    }
    return true;
}

BigDecimalInt BigDecimalInt:: operator=(BigDecimalInt anotherDec){
    number = anotherDec.number;
    return (*this);
}

ostream& operator<<(ostream & out ,BigDecimalInt DecInt){
    int i = (!isdigit(DecInt.number[0])? 1:0);
    if (DecInt.number[0] == '-')
        out << DecInt.number[0];
    for (;i < DecInt.number.size();i++){
        cout << DecInt.number[i];
    }
    return out;
}