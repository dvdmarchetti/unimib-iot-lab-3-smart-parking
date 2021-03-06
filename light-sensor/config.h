#define LED_PIN_1 D2
#define LED_PIN_2 D3
#define LED_PIN_3 D5
#define LED_PIN_4 D6
#define LED_PIN_5 D7
#define LED_PIN_6 D8

#define PHOTORESISTOR_PIN A0

// Json payloads
#define JSON_KEY_DEVICE_MAC "mac"
#define JSON_KEY_DEVICE_TYPE "type"

// Mqtt
#define DEVICE_MAC_ADDRESS "8C:AA:B5:7D:02:01"
#define DEVICE_TYPE "light"

#define MQTT_CLIENTID_WRITER DEVICE_MAC_ADDRESS "_writer"
#define MQTT_CLIENTID_READER DEVICE_MAC_ADDRESS "_reader"

#define MQTT_TOPIC_GLOBAL_CONFIG "smpk/configurations"
#define MQTT_TOPIC_DEVICE_CONFIG MQTT_TOPIC_GLOBAL_CONFIG "/" DEVICE_MAC_ADDRESS
#define MQTT_TOPIC_DEVICE_LAST_WILL "smpk/will/" DEVICE_MAC_ADDRESS
