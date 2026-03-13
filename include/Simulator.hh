#include "Status.h"
#include "QuantumDetector.hh"
#include "QuantumRadar.hh"
#include <bits/stdc++.h>
#include <vector>

using namespace std;

#ifndef SIMULATOR_H
#define SIMULATOR_H

class Simulator
{
    private:
        vector<double> decetorValues;
        QuantumRadar q;
        QuantumDetector d;
        bool hypothesis;

    public:
        Status exportDetectorValues();
        Status monteCarloSampling(int sampleRate);

        double simulateDetector();

        QuantumRadar getQuantumRadar();
        QuantumDetector getQuantumDetector();

        Status setHypothesis(bool hypothesis);
};

#endif