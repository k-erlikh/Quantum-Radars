#include "ClassicalRadar.hh"

using namespace std;

ClassicalRadar::ClassicalRadar()
{
    sig = {0.0, 0.0, 0.0, 0.0};
    gaus = {0.0, 0.0, 0.0, 0.0};
    param = {1.0, 1.0, 0.0, 0.0};

    generateGaussianNorms();
    setParameters();
}

ClassicalRadar::~ClassicalRadar(){}

Status ClassicalRadar::setParameters()
{
    if(hypothesisNULL)
        param.rho = 0;
    else
    {
        uniform_real_distribution<double> dist(nextafter(0.5, 1.0), nextafter(1.0, 0.5));
        param.rho = dist(gen);
    }
    
    normal_distribution<double> dist(0.0,1.0);
    noise.n_i = dist(gen);
    noise.n_q = dist(gen);

    param.alpha = 0.01; 

    return SUCCESS;
}

Status ClassicalRadar::generateSignalSamples()
{
    sig.i_1 = param.sigma_1 * gaus.g1;
    sig.q_1 = param.sigma_1 * gaus.g2;
    sig.i_2 = param.alpha*sig.i_1 + noise.n_i;
    sig.q_2 = param.alpha*sig.q_1 + noise.n_q;

    return SUCCESS;
}


