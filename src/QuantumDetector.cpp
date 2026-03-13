#include "QuantumDetector.hh"

Status QuantumDetector::computeMatchFilterDetection(double RcSum, double RsSum, int samples)
{
    Rc = (1/samples)*(RcSum);
    Rs = (1/samples)*(RsSum);

    DetectorMF = sqrt((Rc*Rc)+(Rs*Rs));
    return SUCCESS;
}