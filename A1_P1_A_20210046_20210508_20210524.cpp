#include "A1_P1_A_20210046_20210508_20210524.h"

BigDecimalInt ::BigDecimalInt()
{
}
//--------------------------------------------------------------------------------------------------------------------------------

BigDecimalInt ::BigDecimalInt(string value_of_number) // setting the number and its size
{
    try
    {
        if (validate_number(value_of_number))
        {

            extract_num_sign_size(value_of_number);
            // size_of_number = value_of_number.size();
        }
        else
        {
            throw invalid_argument("\nBigDecimalInt arguments must be valid numbers");
        }
    }
    catch (std::invalid_argument &alert)
    {
        cerr << alert.what() << endl;
        exit(EXIT_FAILURE);
    }
}
//--------------------------------------------------------------------------------------------------------------------------------

bool BigDecimalInt ::validate_number(string value_of_number)
{
    regex match("[+-]?[0-9]+");
    if (regex_match(value_of_number, match))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//--------------------------------------------------------------------------------------------------------------------------------
void BigDecimalInt ::extract_num_sign_size(string value_of_number)
{
    int start = 0;
    if (value_of_number[0] == '+' || value_of_number[0] == '-')
    {
        sign_value = value_of_number[0];
        start = 1;
    }
    else
    {
        sign_value = '+';
    }
    size_of_number = value_of_number.size() - start;
    number = value_of_number.substr(start, size_of_number);
}

//--------------------------------------------------------------------------------------------------------------------------------
void BigDecimalInt ::set_size(int sz)
{
    for (int i = 0; i < sz; i++)
    {
        number.push_back('0');
    }
}
//--------------------------------------------------------------------------------------------------------------------------------

int BigDecimalInt ::size()
{
    return size_of_number;
}

//--------------------------------------------------------------------------------------------------------------------------------

char BigDecimalInt ::sign()
{
    return sign_value;
}


bool BigDecimalInt:: operator== (BigDecimalInt anotherDec){
    if ((*this).number.size() != anotherDec.number.size() || (*this).sign() != anotherDec.sign()){
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
    sign_value = anotherDec.sign();
    return (*this);
}

ostream& operator<<(ostream & out ,BigDecimalInt DecInt){
    if (DecInt.sign() == '-')
        out << DecInt.sign();

    cout << DecInt.number;
    return out;
}