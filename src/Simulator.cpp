#include "Simulator.hh"

double Simulator::simulateDetectorQuantum()
{
    int N = 100;
    double Rc_totalSamplesSum = 0;
    double Rs_totalSamplesSum = 0;

    for(int n = 0; n < N; n++)
    {
        q.setHypothesis(hypothesis);
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

double Simulator::simulateDetectorClassical()
{
    int N = 100;
    double Rc_totalSamplesSum = 0;
    double Rs_totalSamplesSum = 0;

    for(int n = 0; n < N; n++)
    {
        c.setHypothesis(hypothesis);
        c.setParameters();
        c.generateGaussianNorms();
        c.generateSignalSamples();

        Signals s = c.getSignalSamples();
        Rc_totalSamplesSum += (s.i_1*s.i_2 - s.q_1*s.q_2);
        Rs_totalSamplesSum += (s.i_1*s.i_2 + s.q_1*s.q_2);
    }

    d.computeMatchFilterDetection(Rc_totalSamplesSum, Rs_totalSamplesSum, (double)N);
    return d.getDetectorMFValue();
}


Status Simulator::monteCarloSamplingQuantum(int sampleRate)
{
    for(int n = 0; n < sampleRate; n++)
    {
       qDecetorValues.push_back(simulateDetectorQuantum());
    }
    return SUCCESS;
}

Status Simulator::monteCarloSamplingClassical(int sampleRate)
{
    for(int n = 0; n < sampleRate; n++)
    {
       cDecetorValues.push_back(simulateDetectorClassical());
    }
    return SUCCESS;
}

Status Simulator::exportDetectorValues(string type)
{
    string fileName = "";
    if(type == "quantum")
    {
        if(q.getHypothesis() == true)
            fileName = "data/quantum_DMF_data_H0.csv";
        else
            fileName = "data/quantum_DMF_data_H1.csv";
        
        ofstream file(fileName);
        for(double n : qDecetorValues)
        {
            file << n <<endl;
        }
    }
    
    if(type == "classical")
    {
        if(c.getHypothesis() == true)
            fileName = "data/classical_DMF_data_H0.csv";
        else
            fileName = "data/classical_DMF_data_H1.csv";
        
        ofstream file(fileName);
        for(double n : cDecetorValues)
        {
            file << n <<endl;
        }
    }
    
    return SUCCESS;
}

QuantumRadar Simulator::getQuantumRadar()
{
    return q;
}

Detector Simulator::getDetector()
{
    return d;
}

Status Simulator::setHypothesis(bool hypothesis)
{
    this->hypothesis = hypothesis;
    return SUCCESS;
}