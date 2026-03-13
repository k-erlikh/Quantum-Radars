#include "QuantumRadar.hh"

using namespace std;
mt19937 gen(time(NULL));

QuantumRadar::QuantumRadar()
{
    sig = {0.0, 0.0, 0.0, 0.0};
    gaus = {0.0, 0.0, 0.0, 0.0};
    param = {1.0, 1.0, 0.0, 0.0};

    generateGaussianNorms();
    setParameters();
}

QuantumRadar::~QuantumRadar(){}

Status QuantumRadar::generateGaussianNorms()
{
    normal_distribution<double> dist(0.0,1.0);

    gaus.g1 = dist(gen);
    gaus.g2 = dist(gen);
    gaus.g3 = dist(gen);
    gaus.g4 = dist(gen);

    return SUCCESS;
}

Status QuantumRadar::printGaussianNorms()
{
    cout<<"Gaussian Normal Values: " << gaus.g1 << " " <<gaus.g2 << " " <<gaus.g3 << " " <<gaus.g4 << endl;
    return SUCCESS;
}

Status QuantumRadar::setHypothesis(bool b)
{
    hypothesisNULL = b;
    return SUCCESS;
}

Status QuantumRadar::setParameters()
{
    if(hypothesisNULL)
        param.rho = 0;
    else
    {
        uniform_real_distribution<double> dist(nextafter(0.0, 1.0), nextafter(1.0, 0.0));
        param.rho = dist(gen);
    }
    return SUCCESS;
}

Status QuantumRadar::generateSignalSamples()
{
    sig.i_1 = param.sigma_1 * gaus.g1;
    sig.q_1 = param.sigma_1 * gaus.g2;
    sig.i_2 = param.rho * param.sigma_2 * gaus.g1 + sqrt((1-(param.rho*param.rho)))*param.sigma_2 * gaus.g3;
    sig.q_2 = -param.rho * param.sigma_2 * gaus.g2 + sqrt((1-(param.rho*param.rho)))*param.sigma_2 * gaus.g4;
    return SUCCESS;
}

Signals QuantumRadar::getSignalSamples()
{
    return sig;
}

bool QuantumRadar::getHypothesis()
{
    return hypothesisNULL;
}

// [1] D. Luong, “Quantum Radar Signal Processing,” Jan. 2023, doi: https://doi.org/10.22215/etd/2023-15615.