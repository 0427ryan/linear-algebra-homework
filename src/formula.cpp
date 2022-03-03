
#include "formula.h"

Formula Formula::operator+(Formula &f){
    if(this->vars.size() != f.vars.size()){
        return {{}, 0};
    }
    std::vector<Number> v;
    for(int i = 0 ; i < (int)vars.size() ; i++){
        v.push_back(this->vars[i] + f.vars[i]);
    }
    return {v, this->left + f.left};
}
Formula Formula::operator-(Formula &f){
    if(this->vars.size() != f.vars.size()){
        return {{}, 0};
    }
    std::vector<Number> v;
    for(int i = 0 ; i < (int)vars.size() ; i++){
        v.push_back(this->vars[i] - f.vars[i]);
    }
    return {v, this->left - f.left};
}
Formula Formula::operator*(int i){
    std::vector<Number> v = this->vars;
    for(Number &n : v){
        n *= Number{i, 1};
    }
    return {v, this->left * i};
}
Formula Formula::operator/(int i){
    std::vector<Number> v = this->vars;
    for(Number &n : v){
        n *= Number{1, i};
    }
    return {v, this->left / Number{i}};
};

std::string  Formula::to_string(){
    std::string ret = "";
    for(int i = 0 ; i < (int)vars.size() ; i++){
        if(i != 0 && vars[i].upper < 0){
            ret += "+";
        }
        ret += " " + vars[i].to_string();
    }
    ret += " =" + left.to_string();
    return ret;
}