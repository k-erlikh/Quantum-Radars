#include "Status.h"
#include <vector>
#include <math.h>

using namespace std;

#ifndef QUANTUMDETECTOR_H
#define QUANTUMDETECTOR_H

class QuantumDetector
{
    public:
        Status computeMatchFilterDetection(double RcSum, double RsSum, int samples);

    private:
        double Rc;
        double Rs;
        double DetectorMF;
};

#endif //QUANTUMDETECTOR_H