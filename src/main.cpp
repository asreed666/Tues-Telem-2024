/*
 * Main thread launcher for the City 1082 Telemetry project
 *
 * Each of the RTOS modules will be started by main and then main will sleep
 * forever.
 *
 */
#include "mbed.h"
#include "status.h"
#include "sensors.h"
#include "display.h"
#include "actuators.h"
#include "wifi.h"

Thread statusHandle;
Thread sensorHandle;
Thread displayHandle;
Thread actuatorHandle;
Thread wifiHandle;
// main() runs in its own thread in the OS
int main()
{
    statusHandle.start(callback(statusTask));
    sensorHandle.start(callback(readSensorsTask));
    displayHandle.start(callback(displayTask));
    actuatorHandle.start(callback(doActuations));
    wifiHandle.start(callback(wifiTask));
    while (true) {
        ThisThread::sleep_for(100);
    }
}

