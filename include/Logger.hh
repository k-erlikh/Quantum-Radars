#ifndef LOGGER_H
#define LOGGER_H

#include "Status.h"
#include <string>
#include <queue>
#include <mutex>
#include <thread>
#include <condition_variable>

struct LoggerMessage
{
    std::string fileName;
    double value;
};

class LoggerService
{
private:
    std::queue<LoggerMessage> messageQueue;
    std::mutex queueMutex;
    std::condition_variable queueCv;
    std::thread workerThread;
    bool running;

    void processLoop();

public:
    LoggerService();
    ~LoggerService();

    Status start();
    Status stop();
    Status logValue(const std::string& fileName, double value);
};

#endif