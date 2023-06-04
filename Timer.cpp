#include "Timer.h"

void Timer::start() {
    startTime = std::chrono::high_resolution_clock::now();
}

void Timer::stop() {
    endTime = std::chrono::high_resolution_clock::now();
}

double Timer::getDurationInSeconds() const {
    return std::chrono::duration<double>(endTime - startTime).count();
}

long long Timer::getDurationInMilliseconds() const {
    return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
}

long long Timer::getDurationInMicroseconds() const {
    return std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
}