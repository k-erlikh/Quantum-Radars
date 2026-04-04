#include "Status.h"
#include "Detector.hh"
#include "QuantumRadar.hh"
#include "ClassicalRadar.hh"
#include "Logger.hh"
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

        DetectorService* detectorService;
        LoggerService* loggerService;


        bool hypothesis;

        string buildOutputFileName(const string& type);

    public:
        Simulator();

        Status exportDetectorValues(string type);

        Status monteCarloSamplingQuantum(int sampleRate);
        Status monteCarloSamplingClassical(int sampleRate);

        double simulateDetectorQuantum();
        double simulateDetectorClassical();

        QuantumRadar getQuantumRadar();
        Detector getDetector();

        Status setHypothesis(bool hypothesis);
        Status setServices(DetectorService* detectorSvc, LoggerService* loggerSvc);
};

#endif