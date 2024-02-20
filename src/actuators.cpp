/*
 * Controls outputs from the thing for lights and heating
 */
#include "mbed.h"
#include "actuators.h"
#include "config.h"
#include "display.h"



extern struct MyData {
     float tempC;
     float tempSet; // default thermostat setting
     int heaterState; // 0 for off 1 for on
     float lightL;
     float lightSet; // default ambient light level setting
     int lightState; // 0 lights are off 1 for lights illuminated
} myD;

void doActuations() {
    DigitalOut lightState(LIGHT_LED);
    DigitalOut heaterState(HEATER_LED);
    message_t myMessage;

    while(true) {
        if (myD.lightL < (myD.lightSet - DEAD_BAND_L)) {
            myD.lightState = true;
            lightState = 1;

        }
        else if (myD.lightL > (myD.lightSet + DEAD_BAND_L)){
            myD.lightState = false;
            lightState = 0;          
        }
        if (myD.tempC < myD.tempSet - DEAD_BAND_T) {
            myD.heaterState = true;
            heaterState = 1;
        }
        else if (myD.tempC > myD.tempSet + DEAD_BAND_T){
            myD.heaterState = false;
            heaterState = 0;          
        }

        sprintf(myMessage.buffer, " %s ", myD.lightState?" ON":"OFF");
        myMessage.displayType = LIGHT_ON;
        queueMessage(myMessage);
        ThisThread::sleep_for(10);
        sprintf(myMessage.buffer, " %s ", myD.heaterState?" ON":"OFF");
        myMessage.displayType = HEATER_ON;
        queueMessage(myMessage);
        ThisThread::sleep_for(100);
//        printf("\033[20;1H%f %f %f %d \n%f %d",myD.tempC, myD.tempSet, myD.heaterState,
//                                        myD.lightL, myD.lightSet, myD.lightState);
    }
}