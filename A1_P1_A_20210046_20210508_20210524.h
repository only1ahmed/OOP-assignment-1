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
    BigDecimalInt();
    explicit BigDecimalInt(const string& num);

    //BigDecimalInt(int);
    BigDecimalInt operator+(BigDecimalInt);
    BigDecimalInt operator-(BigDecimalInt);
    bool operator<(BigDecimalInt);
    bool operator>(BigDecimalInt);
    bool operator==(BigDecimalInt);
    BigDecimalInt& operator=(BigDecimalInt);
    int size();
    char sign();
    friend ostream &operator<<(ostream &, BigDecimalInt);

    //additional functions
    void set_size(int);
    void removeLeadingZeroes(BigDecimalInt &);
    bool validate_number(const string&);
    void extract_num_sign_size(string);
    BigDecimalInt pos_pos(BigDecimalInt &);
    BigDecimalInt pos_neg(BigDecimalInt &);
    BigDecimalInt rev_pos_neg(BigDecimalInt &, BigDecimalInt &);
    BigDecimalInt neg_neg(BigDecimalInt &);

};
#endif
