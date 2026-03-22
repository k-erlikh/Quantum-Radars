#include "BaseRadar.hh"

using namespace std;

Status BaseRadar::generateGaussianNorms()
{
    normal_distribution<double> dist(0.0,1.0);

    gaus.g1 = dist(gen);
    gaus.g2 = dist(gen);
    gaus.g3 = dist(gen);
    gaus.g4 = dist(gen);

    return SUCCESS;
}

Status BaseRadar::setHypothesis(bool b)
{
    hypothesisNULL = b;
    return SUCCESS;
}

bool BaseRadar::getHypothesis()
{
    return hypothesisNULL;
}

Signals BaseRadar::getSignalSamples()
{
    return sig;
}