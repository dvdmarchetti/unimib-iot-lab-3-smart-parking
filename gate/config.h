#define SERVO_PIN D4

// Json payloads
#define JSON_KEY_DEVICE_MAC "mac"
#define JSON_KEY_DEVICE_TYPE "type"

// Mqtt
#define DEVICE_MAC_ADDRESS "B4:E6:2D:28:EE:66"
#define DEVICE_TYPE "gate"

#define MQTT_CLIENTID_WRITER DEVICE_MAC_ADDRESS "_writer"
#define MQTT_CLIENTID_READER DEVICE_MAC_ADDRESS "_reader"

#define MQTT_TOPIC_GLOBAL_CONFIG "smpk/configurations"
#define MQTT_TOPIC_DEVICE_CONFIG MQTT_TOPIC_GLOBAL_CONFIG "/" DEVICE_MAC_ADDRESS
#define MQTT_TOPIC_DEVICE_LAST_WILL "smpk/will/" DEVICE_MAC_ADDRESS

// Default config
#define DEFAULT_OPEN_TIME 20000