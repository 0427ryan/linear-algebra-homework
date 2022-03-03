#include <iostream>
#include "number.h"

std::ostream& operator<<(std::ostream &o, Number n){
    if(n.lower == 1){
        return o << n.upper;
    }
    return o << n.upper << '/' << n.lower;
}

int main(int argc, char const *argv[])
{
    Number n1{"-1230"}, n2{"70"};
    n1 += n2;
    std::cout << n1 + n2;
    return 0;
}