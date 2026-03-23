#include "Status.h"
#include "BaseRadar.hh"
#include <random>
#include <iostream>


typedef struct
{
    double sigma_1;
    double sigma_2;
    double rho; // correlation coefficient
    double alpha; // attenuation reflection signal strength
} CParameters;

typedef struct
{
    double n_i;
    double n_q;
} Noise;

#ifndef CLASSICALRADAR_H
#define CLASSICALRADAR_H

class ClassicalRadar : public BaseRadar
{
    private:
        CParameters param;
        Noise noise;

    public:
        ClassicalRadar();
        ~ClassicalRadar();
        Status generateSignalSamples();
        Status setParameters();       
};

#endif //CLASSICALRADAR_H