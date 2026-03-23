#include "Status.h"
#include "Detector.hh"
#include "QuantumRadar.hh"
#include "ClassicalRadar.hh"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

#ifndef SIMULATOR_H
#define SIMULATOR_H

class Simulator
{
    private:
        vector<double> qDecetorValues;
        vector<double> cDecetorValues;

        QuantumRadar q;
        ClassicalRadar c;
        Detector d;

        bool hypothesis;

    public:
        Status exportDetectorValues(string type);

        Status monteCarloSamplingQuantum(int sampleRate);
        Status monteCarloSamplingClassical(int sampleRate);

        double simulateDetectorQuantum();
        double simulateDetectorClassical();

        QuantumRadar getQuantumRadar();
        Detector getDetector();

        Status setHypothesis(bool hypothesis);
};

#endif