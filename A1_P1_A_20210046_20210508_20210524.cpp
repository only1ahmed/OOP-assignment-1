#include "A1_P1_A_20210046_20210508_20210524.h"

BigDecimalInt ::BigDecimalInt()
{
}
//--------------------------------------------------------------------------------------------------------------------------------

//BigDecimalInt ::BigDecimalInt(string value_of_number) // setting the number and its size
//{
//    try
//    {
//        if (validate_number(value_of_number))
//        {
//
//            extract_num_sign_size(value_of_number);
//            // size_of_number = value_of_number.size();
//        }
//        else
//        {
//            throw invalid_argument("\nBigDecimalInt arguments must be valid numbers");
//        }
//    }
//    catch (std::invalid_argument &alert)
//    {
//        cerr << alert.what() << endl;
//        exit(EXIT_FAILURE);
//    }
//}
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
    number = value_of_number.substr(start, size_of_number - start);
}
//--------------------------------------------------------------------------------------------------------------------------------
BigDecimalInt BigDecimalInt ::operator+(BigDecimalInt second_number)
{
    BigDecimalInt result;
    int carry = 0;
    if (this->size_of_number < second_number.size_of_number) // the second number is bigger
    {
        for (int i = this->size_of_number - 1; i >= 0; i--)
        {
            int temp = (second_number.number[i] - '0') + (this->number[i] - '0') + carry;
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
        for (int i = second_number.size_of_number - 1; i >= this->size_of_number; i--)
        {
            int temp = (second_number.number[i] - '0') + carry;
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
        for (int i = second_number.size_of_number - 1; i >= 0; i--)
        {
            int temp = (second_number.number[i] - '0') + (this->number[i] - '0') + carry;
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
        for (int i = this->size_of_number - 1; i >= second_number.size_of_number; i--)
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

int BigDecimalInt::size()
{
    return size_of_number;
}

//--------------------------------------------------------------------------------------------------------------------------------

char BigDecimalInt::sign()
{
    return sign_value;
}
//--------------------------------------------------------------------------------------------------------------------------------

bool BigDecimalInt::operator< (BigDecimalInt num) {
    int cnt = 0;
    if (sign() == num.sign() && sign() == '+') {
        if (number.size() > num.number.size()) {
            return false;
        } else if (number.size() < num.number.size()) {
            return true;
        } else {
            //Here I can use the operator== overloaded to check if they are equal
            for (int i = 0; i < number.size(); ++i) {
                if (number[i] > num.number[i]) // or if not working use getNumber()
                    return false;
                else if (num.number[i] == number[i])
                    cnt++;
            }
        }
        if (cnt == number.size())
            return false;
        return true;
    } else if (sign() == num.sign() && sign() == '-') { // This whole condition needs checking!!!!!!!!!!!!
        if (number.size() > num.number.size()) {
            return true;
        } else if (number.size() < num.number.size()) {
            return false;
        } else {
            //Here I can use the operator== overloaded to check if they are equal
            for (int i = 0; i < number.size(); ++i) {
                if (number[i] > num.number[i]) // or if not working use getNumber()
                    return true;
                else if (num.number[i] == number[i])
                    cnt++;
            }
        }
        if (cnt == number.size())
            return true;
        return false;
    } else {
        if (sign() == '+')
            return false;
        return true;
    }
}

bool BigDecimalInt::operator> (BigDecimalInt num) {
    int cnt = 0;
    if (sign() == num.sign() && sign() == '+') {
        if (number.size() < num.number.size()) {
            return false;
        } else if (number.size() > num.number.size()) {
            return true;
        } else {
            //Here I can use the operator== overloaded to check if they are equal
            for (int i = 0; i < number.size(); ++i) {
                if (number[i] < num.number[i]) // or if not working use getNumber()
                    return false;
                else if (num.number[i] == number[i])
                    cnt++;
            }
        }
        if (cnt == number.size())
            return false;
        return true;
    } else if (sign() == num.sign() && sign() == '-') { // This whole condition needs checking!!!!!!!!!!!!
        if (number.size() > num.number.size()) {
            return false;
        } else if (number.size() < num.number.size()) {
            return true;
        } else {
            //Here I can use the operator== overloaded to check if they are equal
            for (int i = 0; i < number.size(); ++i) {
                if (number[i] > num.number[i]) // or if not working use getNumber()
                    return false;
                else if (num.number[i] == number[i])
                    cnt++;
            }
        }
        if (cnt == number.size())
            return false;
        return true;
    } else {
        if (sign() == '+')
            return true;
        return false;
    }
}


void BigDecimalInt::removeLeadingZeroes(BigDecimalInt & result) {
    int back = result.number.size() - 1;
    while (!(result.number[back] - '0') && back > 0) {
        result.number.erase(back);
        back--;
    }
}

BigDecimalInt BigDecimalInt::pos_neg(BigDecimalInt &num) {
    BigDecimalInt result("");
    //BigDecimalInt nw = *(this);

    string greater_num, smaller_num;
    if (num.number.size() > number.size()) {
        greater_num = num.number;
        smaller_num = number;
    } else if (num.number.size() < number.size()) {
        greater_num = number;
        smaller_num = num.number;
    } else {
        bool num1_is_greater = false;
        for (int i = number.size() - 1; i >= 0; --i) {
            if (number[i] > num.number[i]) {
                greater_num = number;
                smaller_num = num.number;
                num1_is_greater = true;
                break;
            }
        }
        if (!num1_is_greater) {
            greater_num = num.number;
            smaller_num = number;
        }
    }

    for (int i = smaller_num.size() - 1; i >= 0; --i) {
        if (greater_num[i] >= smaller_num[i]) {
            int diff = (greater_num[i] - '0') - (smaller_num[i] - '0');
            result.number += (char) (diff + '0');
        } else {
            for (int j = i - 1; j >= 0; --j) {
                if (greater_num[j] - '0') {
                    greater_num[j]--;
                    int diff = (greater_num[i] - '0' + 10) - (smaller_num[i] - '0');
                    result.number += (char) (diff + '0');
                }
            }
        }
    }
    removeLeadingZeroes(result);
    if (greater_num == num.number && greater_num != number)
        result.number += '-';
    reverse(result.number.begin(), result.number.end());
    return result;
}


BigDecimalInt BigDecimalInt::operator- (BigDecimalInt num) {

    return pos_neg(num);
}
