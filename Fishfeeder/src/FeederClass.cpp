#include "../include/FeederClass.hpp"

int32_t Feeder::_feedInterval = 0;

Feeder::Feeder() {
    // Put initialization like pinMode and begin functions here
    Particle.variable("lastFedTimestamp", _lastFedTimestamp);

    Particle.syncTime();
    waitUntil(Particle.syncTimeDone);
}

Feeder::~Feeder() {
    // Put cleanup code here
}

void Feeder::feed() {
    // Insert code to feed the fish here
    _lastFedTimestamp = Time.now();
}

int Feeder::setFeedInterval(String command) {
  // Expecting the command in the format "HH:MM:SS"
  int colonIndex1 = command.indexOf(':');
  int colonIndex2 = command.indexOf(':', colonIndex1 + 1);

  if (colonIndex1 == -1 || colonIndex2 == -1) {
    // Invalid format, return an error code
    return -1;
  }

  // Extract hours, minutes, and seconds from the string
  int hours = command.substring(0, colonIndex1).toInt();
  int minutes = command.substring(colonIndex1 + 1, colonIndex2).toInt();
  int seconds = command.substring(colonIndex2 + 1).toInt();

  // Validate the values
  if (hours < 0 || minutes < 0 || seconds < 0) {
    // Invalid time values, return an error code
    return -2;
  }

  // Get the current date in time32_t
  _feedInterval = int32_t(hours * 3600 + minutes * 60 + seconds);

  return 0;
}