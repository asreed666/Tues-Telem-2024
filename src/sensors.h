#ifndef SENSORS
#define SENSORS
#define VCC P10_0
#define GND P10_3
#define THERMISTOR P10_1
#define PHOTODIODE P10_2
#define SENSOR_RATE 1000
void readSensorsTask();
#endif