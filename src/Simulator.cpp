#include "Simulator.hh"

double Simulator::simulateDetector()
{
    int N = 100;
    QuantumRadar q;
    QuantumDetector d;
    double Rc_totalSamplesSum = 0;
    double Rs_totalSamplesSum = 0;

    for(int n = 0; n < N; n++)
    {
        q.setParameters();
        q.generateGaussianNorms();
        q.generateSignalSamples();

        Signals s = q.getSignalSamples();
        Rc_totalSamplesSum += (s.i_1*s.i_2 - s.q_1*s.q_2);
        Rs_totalSamplesSum += (s.i_1*s.i_2 + s.q_1*s.q_2);
    }

    d.computeMatchFilterDetection(Rc_totalSamplesSum, Rs_totalSamplesSum, (double)N);
    return d.getDetectorMFValue();
}

Status Simulator::monteCarloSampling(int sampleRate)
{
    for(int n = 0; n < sampleRate; n++)
    {
       decetorValues.push_back(simulateDetector());
    }
    return SUCCESS;
}

Status Simulator::exportDetectorValues()
{
    ofstream file("data.txt");
    for(double n : decetorValues)
    {
        file << n <<endl;
    }
    return SUCCESS;
}