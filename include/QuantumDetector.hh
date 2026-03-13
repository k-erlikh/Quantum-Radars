#include "Status.h"
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

#ifndef QUANTUMDETECTOR_H
#define QUANTUMDETECTOR_H

class QuantumDetector
{
    private:
        double Rc;
        double Rs;
        double detectorMF;
        
    public:
        Status computeMatchFilterDetection(double RcSum, double RsSum, double samples);
        Status printValues();

        double getDetectorMFValue();
};

#endif //QUANTUMDETECTOR_H