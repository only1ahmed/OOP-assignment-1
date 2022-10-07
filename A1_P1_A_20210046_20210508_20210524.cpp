#include "A1_P1_A_20210046_20210508_20210524.h"

BigDecimalInt ::BigDecimalInt() {}

//--------------------------------------------------------------------------------------------------------------------------------

BigDecimalInt::BigDecimalInt(string value_of_number) // setting the number and its size
{
    try
    {
        if (validate_number(value_of_number))
        {
            extract_num_sign_size(value_of_number);
            reverse((this)->number.begin(), (this)->number.end());
            removeLeadingZeroes(*(this));
            reverse((this)->number.begin(), (this)->number.end());
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

BigDecimalInt BigDecimalInt ::operator+(BigDecimalInt &second_number)
{
    if (this->sign_value == '+' && second_number.sign_value == '+')
    {
        return pos_pos(second_number);
    }
    else if (this->sign_value == '+' && second_number.sign_value == '-')
    {
        return pos_neg(second_number);
    }
    else if (this->sign_value == '-' && second_number.sign_value == '+')
    {
        return rev_pos_neg(second_number, *(this));
    }
    else
    {
        return neg_neg(second_number);
    }
}

//--------------------------------------------------------------------------------------------------------------------------------

BigDecimalInt BigDecimalInt::operator- (BigDecimalInt second_number) {
    if (this->sign_value == '+' && second_number.sign_value == '+')
    {
        return pos_neg(second_number);
    }
    else if (this->sign_value == '-' && second_number.sign_value == '-')
    {
        return rev_pos_neg(second_number, *(this));
    }
    else if (this->sign_value == '-' && second_number.sign_value == '+')
    {
        return neg_neg(second_number);
    }
    else //if (this->sign_value == '+' && second_number.sign_value == '-')
    {
        return pos_pos(second_number);
    }
}

//--------------------------------------------------------------------------------------------------------------------------------

bool BigDecimalInt::operator< (BigDecimalInt num) {
    if (sign() == num.sign() && sign() == '+') {
        if (number.size() > num.number.size()) {
            return false;
        } else if (number.size() < num.number.size()) {
            return true;
        } else {
            if (*(this) == num)
                return false;
            for (int i = 0; i < number.size(); ++i) {
                if (number[i] > num.number[i])
                    return false;
            }
        }
        return true;
    } else if (sign() == num.sign() && sign() == '-') {
        if (number.size() > num.number.size()) {
            return true;
        } else if (number.size() < num.number.size()) {
            return false;
        } else {
            if (*(this) == num)
                return false;
            for (int i = 0; i < number.size(); ++i) {
                if (number[i] < num.number[i])
                    return false;
            }
        }
        return true;
    } else {
        if (sign() == '+')
            return false;
        return true;
    }
}

//--------------------------------------------------------------------------------------------------------------------------------

bool BigDecimalInt::operator> (BigDecimalInt num) {
    if (sign() == num.sign() && sign() == '+') {
        if (*(this) == num)
            return false;
        if (number.size() < num.number.size()) {
            return false;
        } else if (number.size() > num.number.size()) {
            return true;
        } else {
            for (int i = 0; i < number.size(); ++i) {
                if (number[i] < num.number[i])
                    return false;
            }
        }
        return true;
    } else if (sign() == num.sign() && sign() == '-') {
        if (*(this) == num)
            return false;
        if (number.size() > num.number.size()) {
            return false;
        } else if (number.size() < num.number.size()) {
            return true;
        } else {
            for (int i = 0; i < number.size(); ++i) {
                if (number[i] > num.number[i])
                    return false;
            }
        }
        return true;
    } else {
        if (sign() == '+')
            return true;
        return false;
    }
}

//--------------------------------------------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------------------------------------------

BigDecimalInt& BigDecimalInt::operator=(BigDecimalInt anotherDec){
    number = anotherDec.number;
    sign_value = anotherDec.sign();
    return (*this);
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

ostream& operator<<(ostream & out ,BigDecimalInt DecInt){
    if (DecInt.sign() == '-')
        out << DecInt.sign();

    out << DecInt.number;
    return out;
}

//--------------------------------------------------------------------------------------------------------------------------------

void BigDecimalInt::removeLeadingZeroes(BigDecimalInt & result) {
    int back = result.number.size() - 1;
    while (!(result.number[back] - '0') && back > 0) {
        result.number.erase(back);
        back--;
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

BigDecimalInt BigDecimalInt::pos_neg(BigDecimalInt &num) {
    BigDecimalInt result;
    string greater_num, smaller_num;

    if (number.size() < num.number.size()) {
        reverse(number.begin(), number.end());
        while (number.size() < num.number.size()) {
            number += '0';
        }
        reverse(number.begin(), number.end());
    } else if (number.size() > num.number.size()) {
        reverse(num.number.begin(), num.number.end());
        while (number.size() > num.number.size()) {
            num.number += '0';
        }
        reverse(num.number.begin(), num.number.end());
    }

    for (int i = 0; i < number.size(); ++i) {
        if (number[i] > num.number[i]) {
            greater_num = number;
            smaller_num = num.number;
            break;
        } else if (number[i] < num.number[i]){
            greater_num = num.number;
            smaller_num = number;
            break;
        }
    }

    if (greater_num == num.number && greater_num != number)
        result.sign_value = '-';

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
                    break;
                }
            }
        }
    }

    removeLeadingZeroes(result);
    reverse((this)->number.begin(), (this)->number.end());
    reverse(num.number.begin(), num.number.end());
    removeLeadingZeroes(*(this));
    removeLeadingZeroes(num);
    reverse((this)->number.begin(), (this)->number.end());
    reverse(num.number.begin(), num.number.end());
    reverse(result.number.begin(), result.number.end());
    result.size_of_number = result.number.size();
    return result;
}

//--------------------------------------------------------------------------------------------------------------------------------

BigDecimalInt BigDecimalInt::rev_pos_neg(BigDecimalInt &num1, BigDecimalInt &num2) {
    BigDecimalInt result;
    string greater_num, smaller_num;

    if (num1.size() < num2.size()) {
        reverse(num1.number.begin(), num1.number.end());
        while (num1.number.size() < num2.number.size()) {
            num1.number += '0';
        }
        reverse(num1.number.begin(), num1.number.end());
    } else if (num1.size() > num2.size()) {
        reverse(num2.number.begin(), num2.number.end());
        while (num1.number.size() > num2.number.size()) {
            num2.number += '0';
        }
        reverse(num2.number.begin(), num2.number.end());
    }

    for (int i = 0; i < num2.number.size(); ++i) {
        if (num2.number[i] > num1.number[i]) {
            greater_num = num2.number;
            smaller_num = num1.number;
            break;
        } else {
            greater_num = num1.number;
            smaller_num = num2.number;
            break;
        }
    }

    if (greater_num == num2.number && greater_num != smaller_num)
        result.sign_value = '-';

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
                    break;
                }
            }
        }
    }
    removeLeadingZeroes(result);
    reverse(num1.number.begin(), num1.number.end());
    reverse(num2.number.begin(), num2.number.end());
    removeLeadingZeroes(num1);
    removeLeadingZeroes(num2);
    reverse(num1.number.begin(), num1.number.end());
    reverse(num2.number.begin(), num2.number.end());

    reverse(result.number.begin(), result.number.end());
    result.size_of_number = result.number.size();
    return result;
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
        result.number[0] = '1';
    }
    result.sign_value = '+';
    reverse(result.number.begin(), result.number.end());
    removeLeadingZeroes(result);
    reverse(result.number.begin(), result.number.end());
    result.size_of_number = result.number.size();
    return result;
}

//--------------------------------------------------------------------------------------------------------------------------------

BigDecimalInt BigDecimalInt::neg_neg(BigDecimalInt &second_number)
{
    BigDecimalInt result = pos_pos(second_number);
    result.sign_value = '-';
    return result;
}
