#ifndef number_h
#define number_h

class Number {
public:
    std::vector<int> dig;
public:
    Number () {}
    
    ~Number () {}
    
    Number (long volume) {
        dig.resize(volume);
        for (long i = 0; i < volume; ++i) {
            dig[i] = (std::rand() % 9) + 1;
        }
        /*
        if (dig[volume - 1] == 0) {         // this gave a RE +_+
            dig[volume - 1] = 1;
        }
        */
    }
    
    Number (long volume, int input) {
        dig.resize(volume);
        for (long i = 0; i < volume; ++i) {
            dig[i] = input;
        }
    }
    
    long size () {
        return dig.size();
    }
    
    /*
    bool operator< (Number & other) {
        if (size() == other.size()) {
            for (long i = other.size() - 1; i >= 0; ++i) {
                if (dig[i] < other.dig[i]) {
                    return true;
                } else if (dig[i] > other.dig[i]) {
                    return false;
                }
            }
        } else if (this -> size() < other.size()) {
            return true;
        }
        return false;
    }
     */
    
    int operator [] (long index) {
        return dig[index];
    }
    
    Number operator + (Number & other) {
        long biggest = std::max(other.size(), size());
        dig.resize(biggest);
        other.dig.resize(biggest);
        Number res(biggest, 0);
        for (long i = 0; i < biggest; ++i) {
            res.dig[i] += dig[i] + other[i];
            if (i == biggest - 1 && res[i] > 9) {
                res.dig.resize(res.size() + 1);
            }
            res.dig[i + 1] += res[i] / 10;
            res.dig[i] %= 10;
        }
        return res;
    }
    
    Number operator - (Number & other) {
        other = other * (-1);
        Number res = *this + other;
        return res;
    }
    
    Number operator * (int mult) {      // multiplying Number by a number from 0 to 9
        Number res(size(), 0);
        for (long i = 0; i < size(); ++i) {
            res.dig[i] += dig[i] * mult;
            if (i == res.size() - 1 && res[i] > 9) {
                res.dig.resize(res.size() + 1);
            }
            res.dig[i + 1] = res.dig[i] / 10;
            res.dig[i] %= 10;
        }
        return res;
    }
    
    Number operator * (Number & other) {        // let this be just a Number of size N
        if (other.size() == 1) {                // multiplyed by a Number of size 1
            return *this * other[0];            // that will be secured by the input
        } else if (size() == 1) {               // it is used only for the base case
            return other * dig[0];              // of the DaC algorithm
        }
        return 0;
    }
    
#include <iostream>
    void Subnumber (Number & other, long start, long end) {
        for (long i = start; i <= end; ++i) {
            this -> dig[i] = other.dig[i];
            std::cout << this -> dig[i];
        }
        std::cout << std::endl;
    }
    
    void Shift (long shift) {
        dig.resize(size() + shift);
    }
};

#endif /* number_h */
