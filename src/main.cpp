#include "Simulator.hh"
using namespace std;

int main()
{
    int N = 10000;

    Simulator s_0;
    s_0.setHypothesis(true);
    s_0.monteCarloSampling(N);
    s_0.exportDetectorValues();
    
    Simulator s_1;
    s_1.setHypothesis(false);
    s_1.monteCarloSampling(N);
    s_1.exportDetectorValues();
}
