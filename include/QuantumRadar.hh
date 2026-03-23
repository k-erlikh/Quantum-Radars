#include "Status.h"
#include "BaseRadar.hh"
#include <iostream>

typedef struct
{
    double sigma_1;
    double sigma_2;
    double rho;
    double phi;
} QParameters;

#ifndef QUANTUMRADAR_H
#define QUANTUMRADAR_H

class QuantumRadar : public BaseRadar
{
    private:
        QParameters param;
    
    public:
        QuantumRadar();
        ~QuantumRadar();

        Status generateSignalSamples();
        Status setParameters();    
};

#endif //QUANTUMRADAR_H



