#include <vector>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <iostream>

#include "Multiplicator.h"      //  the Multiplicator class itself
#include "csvwriter.h"          //  used in order to output in a csv file

const int NUMBER_ALG_APPLICATION = 3;

int main() {
    long k;
    std::cin >> k;
    std::vector<double> GSD_time;
    std::vector<double> DaC_time;
    clock_t clck;
    double temp;
    for (long i = 0; i < k; ++i) {
        temp = 0;
        Multiplicator::Number a(i + 1), b(i + 1);
        //std::cout << a << ' ' << b << std::endl;
        Multiplicator m;
        // timing GSD
        clck = clock();
        for (int j = 0; j < NUMBER_ALG_APPLICATION; ++j) {
            m.GSD(a, b);
            clck = clock() - clck;
            temp += ((double)clck)/(CLOCKS_PER_SEC * NUMBER_ALG_APPLICATION);
        }
        GSD_time.push_back(temp);
        // timing DaC
        clck = clock();
        for (int j = 0; j < NUMBER_ALG_APPLICATION; ++j) {
            m.DaC(a, b);
            clck = clock() - clck;
            temp += ((double)clck)/(CLOCKS_PER_SEC * NUMBER_ALG_APPLICATION);
        }
        //
        DaC_time.push_back(temp);
    }
    //
    CSVWriter output ("out.csv");
    output.algName1 = "GSD";
    output.algName2 = "DaC";
    output.addDatainRow(GSD_time.begin(), GSD_time.end(), DaC_time.begin(), DaC_time.end());
    //
    return 0;
}
