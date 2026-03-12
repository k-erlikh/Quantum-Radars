
#include "Status.h"
#include <random>
#include <iostream>

typedef struct
{
    double i_1;
    double q_1;
    double i_2;
    double q_2;
} Signals;

typedef struct
{
    double g1;
    double g2;
    double g3;
    double g4;
} GaussianValues;

typedef struct
{
    double sigma_1;
    double sigma_2;
    double rho;
    double phi;
} Parameters;

#ifndef QUANTUMRADAR_H
#define QUANTUMRADAR_H

class QuantumRadar
{
    private: 
        Signals sig;
        GaussianValues gaus;
        Parameters param;
        
        bool hypothesisNULL;
    
    public:
        QuantumRadar();
        ~QuantumRadar();
        Status generateGaussianNorms();
        Status printGaussianNorms();
        Status generateSamples();
        Status setHypothesis(bool b);
        Status setParameters();
};

#endif



