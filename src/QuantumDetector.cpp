#include "QuantumDetector.hh"

Status QuantumDetector::computeMatchFilterDetection(double RcSum, double RsSum, double samples)
{
    Rc = (1/samples)*(RcSum);
    Rs = (1/samples)*(RsSum);

    detectorMF = sqrt((Rc*Rc)+(Rs*Rs));
    return SUCCESS;
}

double QuantumDetector::getDetectorMFValue()
{
    return detectorMF;
}

Status QuantumDetector::printValues()
{
    cout<<"Detection Match Filtering Value: "<<detectorMF <<endl;
    return SUCCESS;
}