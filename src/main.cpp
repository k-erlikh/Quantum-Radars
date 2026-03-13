#include "Simulator.hh"
using namespace std;

int main()
{
    Simulator s;
    int N = 10000;
    s.monteCarloSampling(N);
    s.exportDetectorValues();
}
