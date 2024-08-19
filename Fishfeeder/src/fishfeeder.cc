/* 
 * Project myProject
 * Author: Your Name
 * Date: 
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"
#include "../include/feeder_class.h"

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(AUTOMATIC);

// Run the application and system concurrently in separate threads
SYSTEM_THREAD(ENABLED);

// Show system, cloud connectivity, and application logs over USB
// View logs with CLI using 'particle serial monitor --follow'
SerialLogHandler logHandler(LOG_LEVEL_INFO);

int i = 0;
void FeedEventHandler(const char *event, const char *data) {
  i++;
  Log.info("%d: event=%s data=%s", i, event, (data ? data : "NULL"));
}

// setup() runs once, when the device is first turned on
void setup() {
  Particle.function("SetFeedInterval", Feeder::set_feed_interval);
  //Particle.variable("FeedInterval", Feeder::feedInterval);
  Particle.function("GetFeedInterval", Feeder::feed_interval);

  Particle.syncTime();
  waitUntil(Particle.syncTimeDone);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {

  // If feeding time
    // feed()
    // publish feed event

  //Log.info("Sending Hello World to the cloud!");
  //Particle.publish("Hello World");
  
  //delay( 10 * 1000 ); // milliseconds and blocking - see docs for more info!
}