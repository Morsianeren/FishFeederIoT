#ifndef FEEDER_CLASS_H
#define FEEDER_CLASS_H

#include "Particle.h"

class Feeder {
public:
    Feeder();
    ~Feeder();
    // Main function to activate the motor-controlled feeder
    void Feed();
    time32_t last_fed_timestamp() { return last_fed_timestamp_; };

    // Static method to get the feed interval through Particle.function
    // The parameter is not used, but required by Particle.function
    static int32_t feed_interval(String command) { return feed_interval_; }
    // Static method to set the feed interval through Particle.function
    // Returns 0 if successful, -1 if invalid format, -2 if invalid time values
    static int set_feed_interval(String command);

private:
    time32_t last_fed_timestamp_ = 0;
    static int32_t feed_interval_;
};

#endif // FEEDER_CLASS_H