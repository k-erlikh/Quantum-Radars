#include "Detector.hh"

Status Detector::computeMatchFilterDetection(double RcSum, double RsSum, double samples)
{
    Rc = (1/samples)*(RcSum);
    Rs = (1/samples)*(RsSum);

    detectorMF = sqrt((Rc*Rc)+(Rs*Rs));
    return SUCCESS;
}

double Detector::getDetectorMFValue()
{
    return detectorMF;
}

Status Detector::printValues()
{
    cout<<"Detection Match Filtering Value: "<<detectorMF <<endl;
    return SUCCESS;
}