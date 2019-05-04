#ifndef Multiplicator_h
#define Multiplicator_h

class Multiplicator {
public:
    
#include "number.h"
    
    static Number res;
    
    Multiplicator () {}
    
    // grade school method - GSD
    
    Number GSD (Number & oper1, Number & oper2) {
        res.dig.clear();
        long shift = 0;
        for (long i = 0; i < oper1.size(); ++i, ++shift) {
            Number temp = oper2 * oper1[i];
            res.dig.resize(temp.size() + shift);
            for (long t = 0; t < temp.size(); ++t){
                res.dig[t + shift] += temp[t];
            }
        }
        //
        for (long i = 0; i < res.size(); ++i) {
            if (i == res.size() - 1 && res[i] > 9) {
                res.dig.resize(res.size() + 1);
            }
            res.dig[i + 1] += res.dig[i] / 10;
            res.dig[i] %= 10;
        }
        return res;
    }
    
    /*
    // Divide and Conquer - DaC
#include <iostream>
    Number DaC (Number & oper1, Number & oper2) {
        if (oper1.size() == 1 || oper2.size()) {
            //std::cout << oper1[0] << ' ' << oper2[0] << std::endl;
            return oper1 * oper2;               // the base case
        }
        //
        Number left1(oper1.size() / 2);
        left1.Subnumber(oper1, oper1.size() / 2, oper1.size());
        std::cout << left1.dig[0];
        Number right1(oper1.size() / 2);
        right1.Subnumber(oper1, 0, oper1.size() / 2);
        Number left2(oper2.size() / 2);
        left2.Subnumber(oper2, oper2.size() / 2, oper2.size());
        Number right2(oper2.size() / 2);
        right2.Subnumber(oper2, 0, oper2.size() / 2);
        //
        Number temp1 = left1 + right1;
        Number temp2 = left2 + right2;
        Number x1 = DaC(left1, left2);
        Number x2 = DaC(temp1, temp2);
        Number x3 = DaC(left2, right2);
        x2 = x2 - x1;
        x2 = x2 - x3;
        //
        long n = std::max(oper1.size(), oper2.size());
        x1.Shift(n);
        x2.Shift(n / 2);
        return x1 + x2 + x3;
    }
     */
    
    // Divide and Conquer - DaC
    Number DaC (Number & oper1, Number & oper2) {
        long size1 = oper1.size(), size2 = oper2.size();
        long n = std::max(size1, size2);
        if (n == 1) {
            return oper1 * oper2;
        } else {
            Number left1, right1, left2, right2;
            left1.Subnumber(oper1, 0, std::floor(size1/2));
            right1.Subnumber(oper1, std::floor(size1/2) + 1, size1);
            left2.Subnumber(oper2, 0, std::floor(size2/2));
            right2.Subnumber(oper2, std::floor(size2/2) + 1, size2);
            Number temp1 = left1 + right1, temp2 = left2 + right2;
            //
            Number x1 = DaC(right1, right2);
            Number x3 = DaC(left1, left2);
            Number x2 = DaC(temp1, temp2);
            x2 = x2 - x1;
            x2 = x2 - x3;
            x1.Shift(n);
            x2.Shift(n / 2);
            x1 = x1 + x2;
            x1 = x1 + x3;
            return x1;
        }
    }
};
    
Multiplicator::Number Multiplicator::res(1, 0);

//output of a number
#include <iostream>

std::ostream & operator << (std::ostream & os, Multiplicator::Number & oper) {
    for (long i = 0; i < oper.size(); ++i) {
        os << oper.dig[oper.size() - i - 1];
    }
    return os;
}

//output of the time vector
std::ostream & operator << (std::ostream & os, std::vector<std::pair<double, double>> & timer) {
    for (long i = 0; i < timer.size(); ++i) {
        os << timer[i].first << ' ' << timer[i].second << std::endl;
    }
    return os;
}

#endif /* Multiplicator_h */




/*
    // Divide and Conquer - DaC
    Number DaC (Number & oper1, Number & oper2) {
        long size1 = oper1.size(), size2 = oper2.size();
        long n = std::max(size1, size2);
        if (n == 1) {
            return oper1 * oper2;
        } else {
            Number left1(size1/2), right1(size1/2), left2(size2/2), right2(size2/2);
            left1.Subnumber(oper1, 0, size1/2);
            right1.Subnumber(oper1, size1/2, size1);
            left2.Subnumber(oper2, 0, size2/2);
            right2.Subnumber(oper2, size2, size2/2);
            Number temp1 = left1 + right1, temp2 = left2 + right2;
            //
            Number x1 = DaC(right1, right2);
            Number x3 = DaC(left1, left2);
            Number x2 = DaC(temp1, temp2);
            x2 = x2 - x1;
            x2 = x2 - x3;
            x1.Shift(n);
            x2.Shift(n / 2);
            x1 = x1 + x2;
            x1 = x1 + x3;
            
        }
    }
};
*/
