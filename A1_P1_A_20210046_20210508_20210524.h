#ifndef A1_P1_A_20210046_20210508_20210524_H
#define A1_P1_A_20210046_20210508_20210524_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BigDecimalInt
{
private:
    string number;
public:
    BigDecimalInt(string num){
        number = num;
    }
//        BigDecimalInt(int);
//        BigDecimalInt operator+(BigDecimalInt);
//        BigDecimalInt operator-(BigDecimalInt);
//        bool operator<(BigDecimalInt);
//        bool operator>(BigDecimalInt);
    bool operator==(BigDecimalInt);
    BigDecimalInt operator=(BigDecimalInt);
//        int size();
//        int sign();
    friend ostream &operator<<(ostream &, BigDecimalInt);
};
#endif