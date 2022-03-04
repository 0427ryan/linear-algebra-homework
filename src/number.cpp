#include "number.h"

int Number::gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int Number::lcm(int a, int b){
    return a / gcd(a, b) * b;
}
Number::Number(std::string s){
    this->upper = 0;
    this->lower = 1;
    bool isDecimal = false;
    for(auto i : s){
        if(isdigit(i)){
            upper *= 10;
            upper += i - '0';
            if(isDecimal){
                lower *= 10;
            }
        }
    }
    if(s[0] == '-'){
        upper *= -1;
    }
}
Number::Number(int upper, int lower):upper(upper), lower(lower){}
Number Number::upside_down(){
    return {lower, upper};
}
Number Number::operator+(Number n){
    int upper = this->upper * n.lower + n.upper * this->lower;
    int lower = this->lower * n.lower;
    int div = gcd(upper, lower);
    return {upper / div, lower / div};
}
Number Number::operator-(Number n){
    n.upper *= -1;
    return *this + n;
}
Number Number::operator*(Number n){
    return {upper / gcd(upper, n.lower) * n.upper / gcd(n.upper, lower), lower / gcd(n.upper, lower) * n.lower / gcd(upper, n.lower)};
}
Number Number::operator/(Number n){
    return *this * n.upside_down();
}

void Number::operator+=(Number n){
    int upper = this->upper * n.lower + n.upper * this->lower;
    int lower = this->lower * n.lower;
    int div = gcd(upper, lower);
    this->upper = upper / div;
    this->lower = lower / div;
}
void Number::operator-=(Number n){
    n.upper *= -1;
    *this += n;
}
void Number::operator*=(Number n){
    Number temp = *this;
    this->upper = temp.upper / gcd(temp.upper, n.lower) * n.upper / gcd(n.upper, temp.lower);
    this->lower = temp.lower / gcd(n.upper, temp.lower) * n.lower / gcd(temp.upper, n.lower);
}
void Number::operator/=(Number n){
    (*this) *= n.upside_down();
}

