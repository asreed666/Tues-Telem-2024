/*
 * Constants for the telemetry programming system
 */
#ifndef CONFIG
#define CONFIG

#define BLINKING_RATE   500

/* A constant of NCP18XH103F03RB thermistor is */
#define A_COEFF                          (float)(0.0009032679f)
/* B constant of NCP18XH103F03RB thermistor is */
#define B_COEFF                          (float)(0.000248772f)
/* C constant of NCP18XH103F03RB thermistor is */
#define C_COEFF                          (float)(0.0000002041094f)

/* Zero Kelvin in degree C */
#define ABSOLUTE_ZERO                    (float)(-273.15)

#define PD_RESISTOR (float)(10000)

// numeric identifiers for display data/index
#define TEMP_DISPLAY (uint8_t)(1)
#define TEMP_SET (uint8_t)(2)
#define HEATER_ON (uint8_t)(6)
#define LIGHT_DISPLAY (uint8_t)(3)
#define LIGHT_SET (uint8_t)(4)
#define LIGHT_ON (uint8_t)(5)
#define CONNECTED (uint8_t) (10)
#define MESSAGES_SENT (uint8_t)(11)
#define MESSAGES_RCVD (uint8_t)(12)
#define STATUS_DISPLAY (uint8_t)(13)
#define DEAD_BAND_L (float)(10.0f)
#define DEAD_BAND_T (float)(2.0f)

/* MQTT configuration data
 *
 * Set your unique THING_NAME mine is asrThingy
*/

#define BROKER          "192.168.1.176"
#define PORT            1883

#define THING_NAME      "asrThingy"

//#define TEMPERATURE_TOPIC   "/temperatureC"
//#define LIGHT_LEVEL_TOPIC   "/lightlevel"
#define ANNOUNCE_TOPIC      "/announce"
#define LIGHT_SET_TOPIC "asrThingy/lightSet"
#define TEMP_SET_TOPIC "asrThingy/tempSet"


#endif