//
// Created by truma on 11/23/2020.
//

// make noun rather than verb, i.e. "CN Generator"

#include <iostream>
#include "GenerateCN.h"
#include <cmath>
#include "MathFunction.h"

GenerateCN::GenerateCN(int size) {
    CNList(size);
}

void GenerateCN::CNList(int n) {
    listC.clear();
    listC.emplace_back(2/M_PI);
    listC.emplace_back(1);
    // Start at n = 2, where Cn = 1
    for(float i = 3; i <= n; i++){
        double c = getCn(i-1);
        double result = (2*c*pow(M_PI, (i-1)/2) / (pow(M_PI, i/2)))
                * simpsonIntegrate(&cos, M_PI/2, 0, int(i));
        listC.emplace_back(result);
    }
}

double GenerateCN::simpsonIntegrate(double (*f)(double), double uLimit, double lLimit, int power) {

    int intervals = 1000;
    double range = uLimit - lLimit;
    double interval = range/float(intervals);
    double total;
    for(int i = 0; i <= intervals; i++){
        if(i == 0 or i == intervals){
            total += pow(f((i * interval) + lLimit), power);
        }else{
            if(i % 2 == 0){
                total += 2 * pow(f((i * interval) + lLimit), power);
            }else{
                total += 4 * pow(f((i * interval) + lLimit), power);
            }
        }
    }
    total *= (interval/3);
    // work around way to round the double to 4 decimal places
    total = roundf(total * 10000) / 10000;
    // std::cout << total << std::endl;
    return total;
}

double GenerateCN::getCn(int n) {
    std::cout << listC[n-1] << std::endl;
    return listC[n - 1];
}





