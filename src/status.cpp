/*
 * Task to indicate that all is well with the system,
 * flashes an led at 1Hz
 */
#include "mbed.h"
#include "status.h"
#include "config.h"

void statusTask() {
    DigitalOut statusLED(LED1);
    while ( true ) {
        statusLED = !statusLED;
        ThisThread::sleep_for(BLINKING_RATE);
    }
}