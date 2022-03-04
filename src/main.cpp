#include <iostream>
#include <vector>

#include "formula.h"

using namespace std;

std::ostream& operator<<(std::ostream &o, Number n){
    if(n.lower == 1){
        return o << n.upper;
    }
    return o << n.upper << '/' << n.lower;
}

void swap(Formula &f1, Formula &f2){
    Formula temp = f1;
    f1 = f2;
    f2 = temp;
}

void print_marix(vector<Formula> &v){
    for(auto f : v){
        for(auto n : f.vars){
            cout << n << " ";
        }
        cout << f.left << endl;
    }
    cout << endl;
}

void sort_row(vector<Formula> &v, int start, int end, int col){
    cout << "sorting" << endl;
    for(int i = end - 1 ; i > 0 ; i--){
        for(int j = 0 ; j < i ; j++){
            if(v[j].vars[col].upper == 0 && v[j].vars[col].upper != 0){
                cout << "swap (row " << j + 1 << ") and (row " << j + 2 << ")" << endl;
                swap(v[j], v[j+1]);
            }
        }
    }
    cout << "sort finish" << endl << endl;
}

void toRef(vector<Formula> &v){
    cout << "origin: " << endl;
    print_marix(v);

    int begin = 0;
    for(int i = 0 ; i < (int)v[0].vars.size() ; i++){
        sort_row(v, begin, v.size(), i);
        while(i < (int)v[0].vars.size() && v[begin].vars[i].upper == 0){
            i++;
        }
        if(i >= (int)v[0].vars.size()){
            break;
        }
        for(int j = begin + 1 ; j < (int)v.size() && v[j].vars[i].upper != 0 ; j++){
            Number temp = v[j].vars[i] / v[begin].vars[i];
            
            cout << "(row " << j + 1 << ") - (row " << begin + 1 << ") * " << temp << endl;
            
            v[j] = v[j] - v[begin] * temp.upper / temp.lower;
            print_marix(v);
        }

        begin++;
    }

    for(int i = 0 ; i < (int)v.size() ; i++){
        for(Number j : v[i].vars){
            if(j.upper != 0){
                cout << "(row " << i << ") / " << j << endl;
                v[i] = v[i] / j;
                break;
            }
        }
    }
    cout << "ref: " << endl;
    print_marix(v);

}

void toRref(vector<Formula> &v){
    toRef(v);
    for(int i = (int)v.size() - 1 ; i > 0 ; i--){
        for(int j = 0 ; j < i ; j++){
            int temp;
            for(temp = 0 ; temp < (int)v[i].vars.size() && v[i].vars[temp].upper == 0 ; temp++){
            };
            if(temp == (int)v[i].vars.size()){
                continue;
            }
            cout << "(row " << j + 1 << ") - (row " << i + 1 << ") * " << v[j].vars[temp] * v[i].vars[temp] << endl;
            print_marix(v);
            v[j] = v[j] - v[i] / v[i].vars[temp] * v[j].vars[temp];
        }
    }

    cout << "rref: " << endl;
    print_marix(v);
}

int main(int argc, char const *argv[])
{
    vector<Formula> v;                   // ans:  1, 2, 3
    int row;
    int col;
    cout << "Please enter row   : ";
    cin >> row;
    cout << "Please enter column: ";
    cin >> col;
    for(int i = 0 ; i < row ; i++){
        vector<Number> temp;
        int left;
        for(int j = 0 ; j < col ; j++){
            int temp2;
            cin >> temp2;
            temp.push_back({temp2});
        }
        cin >> left;
        v.push_back({temp, left});
    }
    toRref(v);

    return 0;
}