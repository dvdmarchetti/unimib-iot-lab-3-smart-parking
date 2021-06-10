#pragma once

#define PIN_BUZZER D2
#define PIN_PIR D7
#define LED_ESP8266 LED_BUILTIN_AUX
#define PIN_INFO_LED D1

#define INTRUSION_SYSTEM_PERIOD 500

#define PIR_SETUP_PERIOD 60000

#define BLINK_INTERVAL 500

// Json payloads
#define JSON_KEY_DEVICE_MAC "mac"
#define JSON_KEY_DEVICE_TYPE "type"

#define JSON_KEY_CAR_PARK_BUSY "busy"
#define JSON_KEY_CAR_PARK_ON_OFF "status"

// Mqtt
#define DEVICE_MAC_ADDRESS "40:f5:20:05:63:1e"
#define DEVICE_TYPE "intrusion"

#define MQTT_CLIENTID_WRITER DEVICE_MAC_ADDRESS "_writer"
#define MQTT_CLIENTID_READER DEVICE_MAC_ADDRESS "_reader"

#define MQTT_TOPIC_GLOBAL_CONFIG "smpk/configurations"
#define MQTT_TOPIC_DEVICE_CONFIG MQTT_TOPIC_GLOBAL_CONFIG "/" DEVICE_MAC_ADDRESS
#define MQTT_TOPIC_DEVICE_LAST_WILL "smpk/will/" DEVICE_MAC_ADDRESS