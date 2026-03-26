#include "Detector.hh"

Status Detector::computeMatchFilterDetection(double RcSum, double RsSum, double samples)
{
    Rc = (1/samples)*(RcSum);
    Rs = (1/samples)*(RsSum);

    detectorMF = sqrt((Rc*Rc)+(Rs*Rs));
    return SUCCESS;
}

double Detector::getDetectorMFValue()
{
    return detectorMF;
}

Status Detector::printValues()
{
    cout<<"Detection Match Filtering Value: "<<detectorMF <<endl;
    return SUCCESS;
}

DetectorService::DetectorService() : running(false)
{
}

DetectorService::~DetectorService()
{
    stop();
}

void DetectorService::processLoop()
{
    Detector detector;

    while (true)
    {
        DetectorRequest* req = nullptr;

        {
            std::unique_lock<std::mutex> lock(queueMutex);
            queueCv.wait(lock, [this] {
                return !requestQueue.empty() || !running;
            });

            if (!running && requestQueue.empty())
                break;

            req = requestQueue.front();
            requestQueue.pop();
        }

        detector.computeMatchFilterDetection(req->RcSum, req->RsSum, req->samples);
        double result = detector.getDetectorMFValue();

        {
            std::lock_guard<std::mutex> lock(req->responseMutex);
            req->result = result;
            req->completed = true;
        }

        req->responseCv.notify_one();
    }
}

Status DetectorService::start()
{
    if (running)
        return SUCCESS;

    running = true;
    workerThread = std::thread(&DetectorService::processLoop, this);
    return SUCCESS;
}

Status DetectorService::stop()
{
    {
        std::lock_guard<std::mutex> lock(queueMutex);
        if (!running)
            return SUCCESS;
        running = false;
    }

    queueCv.notify_all();

    if (workerThread.joinable())
        workerThread.join();

    return SUCCESS;
}

double DetectorService::sendAndWait(double RcSum, double RsSum, double samples)
{
    DetectorRequest req;
    req.RcSum = RcSum;
    req.RsSum = RsSum;
    req.samples = samples;
    req.result = 0.0;
    req.completed = false;

    {
        std::lock_guard<std::mutex> lock(queueMutex);
        requestQueue.push(&req);
    }

    queueCv.notify_one();

    std::unique_lock<std::mutex> responseLock(req.responseMutex);
    req.responseCv.wait(responseLock, [&req] {
        return req.completed;
    });

    return req.result;
}