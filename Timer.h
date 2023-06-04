#include <chrono>
#include <thread>
#include <iostream>

struct Timer {

    std::chrono::high_resolution_clock::time_point start, end;
    std::chrono::duration<float> duration;

    Timer();
    ~Timer();
};