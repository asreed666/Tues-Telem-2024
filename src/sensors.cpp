/*
 * Read the sensors and store in our telemetry data packet 
 */

 #include "mbed.h"
 #include "sensors.h"
 #include "config.h"

 void readSensorsTask() {
     DigitalOut vcc(VCC);
     DigitalOut gnd(GND);
     AnalogIn tempVolts(THERMISTOR);
     vcc = 1;
     gnd = 0;
     float temperatureVoltage;
     while( true ) {
         temperatureVoltage = tempVolts.read();
         printf( "The temp Voltage is: %2.2f\n", temperatureVoltage);
         ThisThread::sleep_for(SENSOR_RATE);
     }
 }