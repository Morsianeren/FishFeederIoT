#ifndef FEEDER_CLASS_HPP
#define FEEDER_CLASS_HPP

#include "Particle.h"

class Feeder {
public:
    Feeder();
    ~Feeder();
    void feed();
    time32_t getLastFedTimestamp() { return _lastFedTimestamp; };
    static int32_t getFeedInterval(String command) { return _feedInterval; }
    static int setFeedInterval(String command);

private:
    time32_t _lastFedTimestamp = 0;
    static int32_t _feedInterval;
};

#endif // FEEDER_CLASS_HPP