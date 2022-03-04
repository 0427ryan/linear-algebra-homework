#pragma once

#include <string>
#include <vector>
#include "number.h"

class Formula{
public:
    std::vector<Number> vars;
    Number left;
    Formula(std::vector<Number> s, int left){
        this->vars = s;
        this->left = {left, 1};
    };
    Formula(std::vector<Number> s, Number left){
        this->vars = s;
        this->left = left;
    };
    Formula operator+(const Formula &f);
    Formula operator-(const Formula &f);
    Formula operator*(const int i);
    Formula operator/(const int i);
    Formula operator*(const Number i);
    Formula operator/(const Number i);

    std::string to_string();
};