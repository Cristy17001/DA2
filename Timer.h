#include <chrono>

class Timer {
public:
    Timer() : startTime(), endTime() {}

    void start();

    void stop();

    double getDurationInSeconds() const;

    long long getDurationInMilliseconds() const;

    long long getDurationInMicroseconds() const;

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime, endTime;
};
