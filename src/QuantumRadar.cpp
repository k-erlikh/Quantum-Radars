#include "QuantumRadar.hh"

using namespace std;
mt19937 gen(time(NULL));

QuantumRadar::QuantumRadar()
{
    hypothesisNULL = false;
    sig = {0.0, 0.0, 0.0, 0.0};
    gaus = {0.0, 0.0, 0.0, 0.0};
    param = {0.0, 0.0, 0.0, 0.0};

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
    cout<< gaus.g1 << " " <<gaus.g2 << " " <<gaus.g3 << " " <<gaus.g4 << endl;
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
        param.rho = 13321312;
    else
    {
        uniform_real_distribution<double> dist(nextafter(0.0, 1.0), nextafter(1.0, 0.0));
        param.rho = dist(gen);
    }
    cout << "rho: " <<param.rho << endl;
    return SUCCESS;
}

Status QuantumRadar::generateSamples()
{
    return SUCCESS;
}

// [1] D. Luong, “Quantum Radar Signal Processing,” Jan. 2023, doi: https://doi.org/10.22215/etd/2023-15615.