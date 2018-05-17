#include <iostream>
#include <chrono>

#ifndef _TIMER_H_INCLUDED__
#define _TIMER_H_INCLUDED__

class Timer {
private:
    using hrClock = std::chrono::high_resolution_clock;
    using durationDouble = std::chrono::duration<double>;
    std::chrono::time_point<hrClock> start;
public:
    Timer() : start{ hrClock::now() } {}
    void reset() {
        start = hrClock::now();
    }
    double elapsed() const {
        return durationDouble (hrClock::now() - start).count();
    }
};

#endif