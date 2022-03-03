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
    Formula operator+(Formula &f);
    Formula operator-(Formula &f);
    Formula operator*(int i);
    Formula operator/(int i);

    std::string to_string();
};