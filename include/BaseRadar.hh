#include "Status.h"
#include <random>
#include <iostream>

#ifndef BASERADAR_H
#define BASERADAR_H

extern std::mt19937 gen;

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

class BaseRadar
{
    protected: 
        Signals sig;
        GaussianValues gaus;
        bool hypothesisNULL;

    public:
        BaseRadar(){};
        ~BaseRadar(){};

        Status generateGaussianNorms();
        Status setHypothesis(bool b);
        bool getHypothesis();
        Signals getSignalSamples();    
};

#endif //BASERADAR_H