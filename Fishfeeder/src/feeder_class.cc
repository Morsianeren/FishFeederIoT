#include "../include/feeder_class.h"

int32_t Feeder::feed_interval_ = 0;

Feeder::Feeder() {
    // Put initialization like pinMode and begin functions here
    Particle.variable("lastFedTimestamp", last_fed_timestamp_);

    Particle.syncTime();
    waitUntil(Particle.syncTimeDone);
}

Feeder::~Feeder() {
    // Put cleanup code here
}

void Feeder::Feed() {
    // Insert code to feed the fish here
    last_fed_timestamp_ = Time.now();
}

int Feeder::set_feed_interval(String command) {
  // Expecting the command in the format "HH:MM:SS"
  int colon_index_1 = command.indexOf(':');
  int colon_index_2 = command.indexOf(':', colon_index_1 + 1);

  if (colon_index_1 == -1 || colon_index_2 == -1) {
    // Invalid format, return an error code
    return -1;
  }

  // Extract hours, minutes, and seconds from the string
  int hours = command.substring(0, colon_index_1).toInt();
  int minutes = command.substring(colon_index_1 + 1, colon_index_2).toInt();
  int seconds = command.substring(colon_index_2 + 1).toInt();

  // Validate the values
  if (hours < 0 || minutes < 0 || seconds < 0) {
    // Invalid time values, return an error code
    return -2;
  }

  // Get the current date in time32_t
  feed_interval_ = int32_t(hours * 3600 + minutes * 60 + seconds);

  return 0;
}