#include "A1_P1_A_20210046_20210508_20210524.h"

BigDecimalInt ::BigDecimalInt(string value_of_number) // setting the number and its size
{
    try
    {
        if (validate_number(value_of_number))
        {

            extract_num_and_sign(value_of_number);
            size_of_number = value_of_number.size();
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
    regex match("(+-)?[0-9]+");
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
BigDecimalInt BigDecimalInt ::operator+(BigDecimalInt *second_number)
{
    BigDecimalInt result;
    int carry = 0;
    if (this->size_of_number < second_number->size_of_number) // the second number is bigger
    {
        for (int i = this->size_of_number - 1; i >= 0; i--)
        {
            int temp = (second_number->number[i] - '0') + (this->number[i] - '0') + carry;
            if (temp > 9)
            {
                temp -= 10;
                carry = 1;
                result.number[i] = (char)(temp + '0');
            }
            else
            {
                carry = 0;
                result.number[i] = (char)(temp + '0');
            }
        }
        for (int i = second_number->size_of_number - 1; i >= this->size_of_number; i--)
        {
            int temp = (second_number->number[i] - '0') + carry;
            if (temp > 9)
            {
                temp -= 10;
                carry = 1;
                result.number[i] = (char)(temp + '0');
            }
            else
            {
                carry = 0;
                result.number[i] = (char)(temp + '0');
            }
        }
    }
    else
    {
        for (int i = second_number->size_of_number - 1; i >= 0; i--)
        {
            int temp = (second_number->number[i] - '0') + (this->number[i] - '0') + carry;
            if (temp > 9)
            {
                temp -= 10;
                carry = 1;
                result.number[i] = (char)(temp + '0');
            }
            else
            {
                carry = 0;
                result.number[i] = (char)(temp + '0');
            }
        }
        for (int i = this->size_of_number - 1; i >= second_number->size_of_number; i--)
        {
            int temp = (this->number[i] - '0') + carry;
            if (temp > 9)
            {
                temp -= 10;
                carry = 1;
                result.number[i] = (char)(temp + '0');
            }
            else
            {
                carry = 0;
                result.number[i] = (char)(temp + '0');
            }
        }
    }
    return result;
}
//--------------------------------------------------------------------------------------------------------------------------------

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
//--------------------------------------------------------------------------------------------------------------------------------
