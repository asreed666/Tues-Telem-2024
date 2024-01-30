/*
 * Read the sensors and store in our telemetry data packet 
 */

 #include "mbed.h"
 #include "sensors.h"
 #include "config.h"
 #include "display.h"

 void readSensorsTask() {
     message_t myMessage;
     DigitalOut vcc(VCC);
     DigitalOut gnd(GND);
     AnalogIn tempVolts(THERMISTOR);
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
         ThisThread::sleep_for(SENSOR_RATE);
     }
 }