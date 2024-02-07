/*
 * Read the sensors and store in our telemetry data packet 
 */

 #include "mbed.h"
 #include "sensors.h"
 #include "config.h"
 #include "display.h"

 struct myData{
     float tempC;
     float tempSet = 22.0f; // default thermostat setting
     int heaterState = 0; // 0 for off 1 for on
     float lightL;
     float lightSet = 50.0f; // default ambient light level setting
     int lightState = 0; // 0 lights are off 1 for lights illuminated
 } myD;

 void readSensorsTask() {
     message_t myMessage;

     sprintf(myMessage.buffer, "%2.1fC", myD.tempSet);
     myMessage.displayType = TEMP_SET;
     queueMessage(myMessage);

     sprintf(myMessage.buffer, "%s", myD.heaterState?" ON":"OFF");
     myMessage.displayType = HEATER_ON;
     queueMessage(myMessage);

     sprintf(myMessage.buffer, "%2.1f%c", myD.lightSet, '%');
     myMessage.displayType = LIGHT_SET;
     queueMessage(myMessage);

     sprintf(myMessage.buffer, "%s", myD.lightState?" ON":"OFF");
     myMessage.displayType = LIGHT_ON;
     queueMessage(myMessage);


     DigitalOut vcc(VCC);
     DigitalOut gnd(GND);
     AnalogIn tempVolts(THERMISTOR);
     AnalogIn lightVolts(PHOTODIODE);
     vcc = 1;
     gnd = 0;
     float temperatureVoltage;

     while( true ) {
        temperatureVoltage = tempVolts.read() * 2.4; // vref for adc is 1.2 * 2 => 2.4 * reading for voltage
        float current = (3.3 - temperatureVoltage) / PD_RESISTOR;
        float thermResistance = temperatureVoltage / current;
        float logrT = (float32_t)log((float64_t)thermResistance);
        /* Calculate temperature from the resistance of thermistor using
        * Steinhart-Hart Equation */
        float stEqn = (float32_t)((A_COEFF) + ((B_COEFF)*logrT) +
                                  ((C_COEFF)*pow((float64)logrT, (float32)3)));
        float temperatureC = (float32_t)(((1.0 / stEqn) + ABSOLUTE_ZERO) + 0.05);

         sprintf( myMessage.buffer, "%2.1fC \n", temperatureC);
         myMessage.displayType = TEMP_DISPLAY;
//         printf("%d %s\n", myMessage.displayType, myMessage.buffer);
         queueMessage(myMessage);
         ThisThread::sleep_for(10);
         float lightLevel = lightVolts.read() * 100;
         sprintf( myMessage.buffer, "%3.1f%c ", lightLevel, '%');
         myMessage.displayType = LIGHT_DISPLAY;
//         printf("%d %s\n", myMessage.displayType, myMessage.buffer);
         queueMessage(myMessage);         

         ThisThread::sleep_for(SENSOR_RATE);
     }
 }