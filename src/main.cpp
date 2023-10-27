
#include <iostream>

//#include "A111.hpp"

bool  sum_factors(int value1, int value2);

int main(int argc, char** argv){
    
    //A111 a111object;
    std::cout << "blabla \n";    
    //a111object.printA111Version();
    
    int a = 3;
    int b = 5;
    bool c;
    int *pointer;
    bool &referenz = c;
    
    
    c = sum_factors(a,b);
    
    
    
    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "b = " << b << "\n";

    return 0;
}

bool sum_factors(int value1, int value2){
    if(value1 < value2){
        return true;
    }else{
        return false;
    }
}

