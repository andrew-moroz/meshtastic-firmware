// Note: *This* configuration is working as of 6.17.23, 12:17pm
// Setup:
//      * Feather S3 soldered to perf board with sockets
//      * E22 soldered to other perf board with other sockets

// I conclude it's likely there is something wrong with the other E22; probably got fried in one of my many rounds of experimentation
// This setup is *mostly* working, but initially I experienced several (like 10+) reboots upon sending a message to another node
//      * (this was while connected to the E22 node [ad5c] from meshtastic macOS app running, sending to 4b83)
//      * (was also logging serial output via minicom; occurred to me that maybe this is somehow related)



// For OLED LCD
#define I2C_SDA 3
#define I2C_SCL 4

// GPS
// #undef GPS_RX_PIN
// #define GPS_RX_PIN 15
//#undef GPS_TX_PIN
//#define GPS_TX_PIN 12 // not connected

#define BUTTON_PIN 39 // NOTE: this looks like it should be 0 on the Feather S3; leaving it for now since it was working before // The middle button GPIO on the T-Beam
// #define BATTERY_PIN 34 // A battery voltage measurement pin, voltage divider connected here to measure battery voltage

#define ADC_MULTIPLIER 1.85 // (R1 = 470k, R2 = 680k)
#define EXT_NOTIFY_OUT NOT_A_PIN // Overridden default pin to use for Ext Notify Module (#975).
#define LED_PIN 21 // add status LED (compatible with core-pcb and DIY targets)

#define LORA_DIO0 26  // a No connect on the SX1262/SX1268 module
#define LORA_RESET 14 // RST for SX1276, and for SX1262/SX1268
#define LORA_DIO1 13  // IRQ for SX1262/SX1268
#define LORA_DIO2 38  // BUSY for SX1262/SX1268
#define LORA_DIO3     // Not connected on PCB, but internally on the TTGO SX1262/SX1268, if DIO3 is high the TXCO is enabled

#define RF95_SCK 36
#define RF95_MISO 37
#define RF95_MOSI 35
#define RF95_NSS 10

// not sure whether we need these?
// #define PIN_SPI_MISO 37
// #define PIN_SPI_MOSI 35
// #define PIN_SPI_SCK 36

// supported modules list
#define USE_RF95 // RFM95/SX127x
#define USE_SX1262
#define USE_SX1268
#define USE_LLCC68

// common pinouts for SX126X modules
#define SX126X_CS 10 // NSS for SX126X
#define SX126X_DIO1 LORA_DIO1
#define SX126X_BUSY LORA_DIO2
#define SX126X_RESET LORA_RESET
// #define SX126X_RXEN 11
#define SX126X_RXEN RADIOLIB_NC
#define SX126X_TXEN 9

#define SX126X_MAX_POWER 22

// RX/TX for RFM95/SX127x
// #define RF95_RXEN 14
// #define RF95_TXEN 13

#ifdef EBYTE_E22
// Internally the TTGO module hooks the SX126x-DIO2 in to control the TX/RX switch
// (which is the default for the sx1262interface code)
#define SX126X_E22
#endif
