#ifndef A1_P1_A_20210046_20210508_20210524_H
#define A1_P1_A_20210046_20210508_20210524_H
#include <iostream>
#include <string>
#include <vector>
#include <regex>
using namespace std;

class BigDecimalInt
{
private:
    string number;
    int size_of_number;
    char sign_value;

public:
    BigDecimalInt();       // empty constructor
    BigDecimalInt(string); // reciving a number
    void set_size(int);
    bool validate_number(string);
    void extract_num_sign_size(string);
    BigDecimalInt operator+(BigDecimalInt &);
    BigDecimalInt pos_pos(BigDecimalInt &);
    BigDecimalInt neg_neg(BigDecimalInt &);
    bool operator==(BigDecimalInt);
    BigDecimalInt operator=(BigDecimalInt);
    int size();
    char sign();
    friend ostream &operator<<(ostream &, BigDecimalInt);
    BigDecimalInt operator-(BigDecimalInt);
    bool operator<(BigDecimalInt);
    bool operator>(BigDecimalInt);
    // additional functions
    void removeLeadingZeroes(BigDecimalInt &);
    BigDecimalInt pos_neg(BigDecimalInt &);
    BigDecimalInt rev_pos_neg(BigDecimalInt &, BigDecimalInt &);
};
#endif
