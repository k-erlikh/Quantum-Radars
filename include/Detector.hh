#include "Status.h"
#include <vector>
#include <math.h>
#include <iostream>
#include <queue>
#include <mutex>
#include <thread>
#include <condition_variable>

using namespace std;

#ifndef DETECTOR_H
#define DETECTOR_H

class Detector
{
    private:
        double Rc;
        double Rs;
        double detectorMF;
        
    public:
        Status computeMatchFilterDetection(double RcSum, double RsSum, double samples);
        Status printValues();

        double getDetectorMFValue();
};

struct DetectorRequest
{
    double RcSum;
    double RsSum;
    double samples;

    double result;
    bool completed;

    std::mutex responseMutex;
    std::condition_variable responseCv;
};

class DetectorService
{
private:
    std::queue<DetectorRequest*> requestQueue;
    std::mutex queueMutex;
    std::condition_variable queueCv;
    std::thread workerThread;
    bool running;

    void processLoop();

public:
    DetectorService();
    ~DetectorService();

    Status start();
    Status stop();
    double sendAndWait(double RcSum, double RsSum, double samples);
};


#endif //DETECTOR_H