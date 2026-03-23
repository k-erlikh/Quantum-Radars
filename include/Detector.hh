#include "Status.h"
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

#ifndef DETECTOR_H
#define DETECTOR_H

class Detector
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

#endif //DETECTOR_H