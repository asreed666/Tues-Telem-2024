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


#endif