//
// Created by truma on 11/23/2020.
//

#ifndef MONTECARLOPI_GENERATECN_H
#define MONTECARLOPI_GENERATECN_H

#include <vector>
#include "math.h"

class GenerateCN {
public:
    GenerateCN(int);
    void CNList(int n);
    double simpsonIntegrate(double (*f)(double), double uLimit, double lLimit, int power);
    double getCn(int n);

private:
    std::vector<double> listC;
};


#endif //MONTECARLOPI_GENERATECN_H
