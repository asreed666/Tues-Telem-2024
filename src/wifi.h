#ifndef WIFI
#define WIFI
#define PUB_PERIOD 20
void wifiTask();
constexpr int NUM_TOPICS = 20;
constexpr int TOPIC_LEN = 80;
void sendPub( int topic, float value);
constexpr auto LIGHT_LEVEL_TOPIC = 0;
constexpr auto LIGHT_STATE_TOPIC = 1;
constexpr auto LIGHT_SWITCH_TOPIC = 2;
constexpr auto REDLED_TOPIC = 3;
constexpr auto GREENLED_TOPIC = 4;
constexpr auto BLUELED_TOPIC = 5;
constexpr auto ANNOUNCE_TOPIC_NUM = 6;
constexpr auto LIGHT_THRESH_TOPIC = 7;
constexpr auto LATITUDE_TOPIC = 8;
constexpr auto LONGITUDE_TOPIC = 9;
constexpr auto TEMPERATURE_TOPIC = 10;
constexpr auto TEMP_THRESH_TOPIC = 11;
constexpr auto RX_COUNT = 12;
constexpr auto TX_COUNT = 13;
constexpr auto TIME = 14;
constexpr auto STATUSLED_TOPIC = 15;
constexpr auto ORANGELED_TOPIC = 16;
constexpr auto HEATER_STATE_TOPIC = 17;
constexpr auto HEATER_SWITCH_TOPIC = 18;
constexpr auto REL_HUMIDITY_TOPIC = 19;
#define RXLED P0_5

#endif