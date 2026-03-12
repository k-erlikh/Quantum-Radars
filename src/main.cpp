#include "QuantumRadar.hh"
using namespace std;

int main()
{
    QuantumRadar q;
    q.printGaussianNorms();
    q.generateSignalSamples();
    QuantumRadar p;
    p.printGaussianNorms();
    p.generateSignalSamples();
}
