#pragma once

#include <string>

class Number{
public:
    int upper;
    int lower;
    static int lcm(int a, int b);
    Number() = default;
    Number(std::string s);
    Number(int upper, int lower);
    Number(int upper):Number(upper, 1){};
    Number upside_down();
    Number operator+(Number n);
    Number operator-(Number n);
    Number operator*(Number n);
    Number operator/(Number n);

    void operator+=(Number n);
    void operator-=(Number n);
    void operator*=(Number n);
    void operator/=(Number n);

    inline std::string to_string(){
        if(upper == 0){
            return "0";
        }
        return lower == 1 ? upper + "" : upper + "/" + lower;
    }
};
