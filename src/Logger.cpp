#include "Logger.hh"
#include <fstream>

LoggerService::LoggerService() : running(false)
{
}

LoggerService::~LoggerService()
{
    stop();
}

void LoggerService::processLoop()
{
    while (true)
    {
        LoggerMessage msg;

        {
            std::unique_lock<std::mutex> lock(queueMutex);
            queueCv.wait(lock, [this] {
                return !messageQueue.empty() || !running;
            });

            if (!running && messageQueue.empty())
                break;

            msg = messageQueue.front();
            messageQueue.pop();
        }

        std::ofstream file(msg.fileName, std::ios::app);
        if (file.is_open())
        {
            file << msg.value << std::endl;
        }
    }
}

Status LoggerService::start()
{
    if (running)
        return SUCCESS;

    running = true;
    workerThread = std::thread(&LoggerService::processLoop, this);
    return SUCCESS;
}

Status LoggerService::stop()
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

Status LoggerService::logValue(const std::string& fileName, double value)
{
    {
        std::lock_guard<std::mutex> lock(queueMutex);
        messageQueue.push({fileName, value});
    }

    queueCv.notify_one();
    return SUCCESS;
}