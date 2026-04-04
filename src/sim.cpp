#include "Simulator.hh"
#include "Logger.hh"
#include <random>
#include <ctime>
#include <fstream>
#include <cstdlib>
using namespace std;

std::mt19937 gen(time(NULL));

static void clearOutputFiles()
{
    system("mkdir -p data");

    ofstream("data/quantum_DMF_data_H0.csv", ios::trunc).close();
    ofstream("data/quantum_DMF_data_H1.csv", ios::trunc).close();
    ofstream("data/classical_DMF_data_H0.csv", ios::trunc).close();
    ofstream("data/classical_DMF_data_H1.csv", ios::trunc).close();
}

int main()
{
    int N = 100000;

    clearOutputFiles();

    DetectorService detectorService;
    LoggerService loggerService;

    detectorService.start();
    loggerService.start();

    Simulator s_0;
    s_0.setServices(&detectorService, &loggerService);
    s_0.setHypothesis(true);
    s_0.monteCarloSamplingQuantum(N);
    s_0.exportDetectorValues("quantum");

    Simulator s_1;
    s_1.setServices(&detectorService, &loggerService);
    s_1.setHypothesis(false);
    s_1.monteCarloSamplingQuantum(N);
    s_1.exportDetectorValues("quantum");
    
    Simulator s_2;
    s_2.setServices(&detectorService, &loggerService);
    s_2.setHypothesis(true);
    s_2.monteCarloSamplingClassical(N);
    s_2.exportDetectorValues("classical");
    
    Simulator s_3;
    s_3.setServices(&detectorService, &loggerService);
    s_3.setHypothesis(false);
    s_3.monteCarloSamplingClassical(N);
    s_3.exportDetectorValues("classical");

    loggerService.stop();
    detectorService.stop();

    return 0;
}
