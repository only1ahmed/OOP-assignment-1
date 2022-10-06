#ifndef A1_P1_A_20210046_20210508_20210524_H
#define A1_P1_A_20210046_20210508_20210524_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BigDecimalInt{
private:
    string number;
public:
    BigDecimalInt (string decStr);
    BigDecimalInt (int decInt);
    BigDecimalInt operator+ (BigDecimalInt anotherDec);
    BigDecimalInt operator- (BigDecimalInt);
    bool operator< (BigDecimalInt anotherDec);
    bool operator> (BigDecimalInt anotherDec);
    bool operator==(BigDecimalInt anotherDec);
    BigDecimalInt operator= (BigDecimalInt anotherDec);
    int size();
    int sign();
    friend ostream& operator << (ostream& out, BigDecimalInt b);
};
#endif