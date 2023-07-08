#ifndef TIMER_H
#define TIMER_H

#include<chrono>
#include<iostream>

class Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<double> elapsed_seconds;
    public:
    void begin() {
        start = std::chrono::high_resolution_clock::now();
    }

    void stop() {
        end = std::chrono::high_resolution_clock::now();
        elapsed_seconds = end - start;
    }

    double getElapsedSeconds() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_seconds).count();
    }
};
#endif