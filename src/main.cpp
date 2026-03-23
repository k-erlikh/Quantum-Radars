#include "Simulator.hh"
#include <random>
#include <ctime>
using namespace std;

std::mt19937 gen(time(NULL));

int main()
{
    int N = 10000;

    Simulator s_0;
    s_0.setHypothesis(true);
    s_0.monteCarloSamplingQuantum(N);
    s_0.exportDetectorValues("quantum");

    Simulator s_1;
    s_1.setHypothesis(false);
    s_1.monteCarloSamplingQuantum(N);
    s_1.exportDetectorValues("quantum");
    
    Simulator s_2;
    s_2.setHypothesis(true);
    s_2.monteCarloSamplingClassical(N);
    s_2.exportDetectorValues("classical");
    
    Simulator s_3;
    s_3.setHypothesis(false);
    s_3.monteCarloSamplingClassical(N);
    s_3.exportDetectorValues("classical");
}
