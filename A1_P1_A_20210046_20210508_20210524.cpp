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
BigDecimalInt BigDecimalInt ::operator+(BigDecimalInt &second_number)
{
    if (this->sign_value == '+' && second_number.sign_value == '+')
    {
        return pos_pos(second_number);
    }
    else if ((this->sign_value == '-' && second_number.sign_value == '+') || (this->sign_value == '+' && second_number.sign_value == '-'))
    {
        return pos_neg(second_number);
    }
    else
    {
        return neg_neg(second_number);
    }
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
//--------------------------------------------------------------------------------------------------------------------------------
BigDecimalInt BigDecimalInt::pos_pos(BigDecimalInt &second_number)
{
    BigDecimalInt result;
    result.set_size((max(this->size_of_number, second_number.size_of_number) + 1));
    int carry = 0;
    if (this->size_of_number < second_number.size_of_number) // the second number is bigger
    {
        int delta = second_number.size_of_number - this->size_of_number;
        for (int i = this->size_of_number - 1; i >= 0; i--)
        {
            int temp = (second_number.number[i + delta] - '0') + (this->number[i] - '0') + carry;
            if (temp > 9)
            {
                temp -= 10;
                carry = 1;
                result.number[i + delta + 1] = (char)(temp + '0');
            }
            else
            {
                carry = 0;
                result.number[i + delta + 1] = (char)(temp + '0');
            }
        }
        for (int i = delta - 1; i >= 0; i--)
        {
            int temp = (second_number.number[i] - '0') + carry;
            if (temp > 9)
            {
                temp -= 10;
                carry = 1;
                result.number[i + 1] = (char)(temp + '0');
            }
            else
            {
                carry = 0;
                result.number[i + 1] = (char)(temp + '0');
            }
        }
    }
    else
    {
        int delta = this->size_of_number - second_number.size_of_number;

        for (int i = second_number.size_of_number - 1; i >= 0; i--)
        {
            int temp = (second_number.number[i] - '0') + (this->number[i + delta] - '0') + carry;
            if (temp > 9)
            {
                temp -= 10;
                carry = 1;
                result.number[i + delta + 1] = (char)(temp + '0');
            }
            else
            {
                carry = 0;
                result.number[i + delta + 1] = (char)(temp + '0');
            }
        }
        for (int i = delta - 1; i >= 0; i--)
        {
            int temp = (this->number[i] - '0') + carry;
            if (temp > 9)
            {
                temp -= 10;
                carry = 1;
                result.number[i + 1] = (char)(temp + '0');
            }
            else
            {
                carry = 0;
                result.number[i + 1] = (char)(temp + '0');
            }
        }
    }
    if (carry)
    {
        result.number[0] = 1;
    }
    result.sign_value = '+';
    reverse(result.number.begin(), result.number.end());
    removeLeadingZeroes(result);
    reverse(result.number.begin(), result.number.end());
    result.size_of_number = result.number.size();
    return result;
}

BigDecimalInt BigDecimalInt ::neg_neg(BigDecimalInt &second_number)
{
    BigDecimalInt result = pos_pos(second_number);
    result.sign_value = '-';
    return result;
<<<<<<< HEAD
}
=======
}
>>>>>>> 72df5e58980600e8ef681d3302153274892bfd90
