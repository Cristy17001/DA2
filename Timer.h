#include <chrono>

/**
 * @class Timer
 * @brief A class for measuring the duration of code execution.
 */
class Timer {
public:
    /**
     * @brief Constructs a Timer object.
     */
    Timer() : startTime(), endTime() {}

    /**
     * @brief Starts the timer.
     */
    void start();

    /**
     * @brief Stops the timer.
     */
    void stop();

    /**
     * @brief Gets the duration of the timer in seconds.
     * @return The duration in seconds.
     */
    double getDurationInSeconds() const;

    /**
     * @brief Gets the duration of the timer in milliseconds.
     * @return The duration in milliseconds.
     */
    long long getDurationInMilliseconds() const;

    /**
     * @brief Gets the duration of the timer in microseconds.
     * @return The duration in microseconds.
     */
    long long getDurationInMicroseconds() const;

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime, endTime;
};
