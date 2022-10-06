#include "A1_P1_A_20210046_20210508_20210524.h"

BigDecimalInt ::BigDecimalInt()
{
}
//--------------------------------------------------------------------------------------------------------------------------------

BigDecimalInt ::BigDecimalInt(const string& value_of_number) // setting the number and its size
{
    try
    {
        if (validate_number(value_of_number))
        {
            extract_num_sign_size(value_of_number);
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

bool BigDecimalInt ::validate_number(const string& value_of_number)
{
    regex match("[+-]?[0-9]+");
    if (regex_match(value_of_number, match))
    {
        return true;
    }
    else
    {
        return false;
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

//--------------------------------------------------------------------------------------------------------------------------------

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

void BigDecimalInt::removeLeadingZeroes(BigDecimalInt & result) {
    int back = result.number.size() - 1;
    while (!(result.number[back] - '0') && back > 0) {
        result.number.erase(back);
        back--;
    }
}

//--------------------------------------------------------------------------------------------------------------------------------

BigDecimalInt BigDecimalInt::pos_neg(BigDecimalInt &num) {
    BigDecimalInt result;
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
        result.sign_value = '-';
    reverse(result.number.begin(), result.number.end());
    return result;
}

//--------------------------------------------------------------------------------------------------------------------------------

BigDecimalInt BigDecimalInt::rev_pos_neg(BigDecimalInt &num1, BigDecimalInt &num2) {
    BigDecimalInt result;
    string greater_num, smaller_num;

    if (num1.number.size() > num2.number.size()) {
        greater_num = num1.number;
        smaller_num = num2.number;
    } else if (num1.number.size() < num2.number.size()) {
        greater_num = num2.number;
        smaller_num = num1.number;
    } else {
        bool num1_is_greater = false;
        for (int i = num2.number.size() - 1; i >= 0; --i) {
            if (num2.number[i] > num1.number[i]) {
                greater_num = num2.number;
                smaller_num = num1.number;
                num1_is_greater = true;
                break;
            }
        }
        if (!num1_is_greater) {
            greater_num = num1.number;
            smaller_num = num2.number;
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
    if (greater_num == num2.number && greater_num != num1.number)
        result.sign_value += '-';
    reverse(result.number.begin(), result.number.end());
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
        result.number[0] = 1;
    }
    result.sign_value = '+';
    reverse(result.number.begin(), result.number.end());
    removeLeadingZeroes(result);
    reverse(result.number.begin(), result.number.end());
    result.size_of_number = result.number.size();
    return result;
}

//--------------------------------------------------------------------------------------------------------------------------------

BigDecimalInt BigDecimalInt ::neg_neg(BigDecimalInt &second_number)
{
    BigDecimalInt result = pos_pos(second_number);
    result.sign_value = '-';
    return result;
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

BigDecimalInt& BigDecimalInt:: operator=(BigDecimalInt anotherDec){
    number = anotherDec.number;
    sign_value = anotherDec.sign();
    return (*this);
}

//--------------------------------------------------------------------------------------------------------------------------------

ostream& operator<<(ostream & out ,BigDecimalInt DecInt){
    if (DecInt.sign() == '-')
        out << DecInt.sign();

    cout << DecInt.number;
    return out;
}