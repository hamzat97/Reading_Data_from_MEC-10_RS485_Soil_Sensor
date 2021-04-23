/*
* This sketch allows you to read data from MEC-10 RS485 soil sensor using some popular and widely used development boards (Arduino boards, ESP32 TTGO, LoRa32u4 and Heltec Wireless Stick Lite).
* More boards will be supported in future releases.
*/

#include <ModbusMaster.h> // Include Modbus library

// If you're using arduino board, uncomment the variables defined below 
/* 
// The Data Enable and Receiver Enable pins of the MAX485 module converter, are hooked up as follows:
#define DE 8
#define RE 8
*/

// If you're using LoRa32u4 board, uncomment the variables defined below
/*
// The Data Enable and Receiver Enable pins of the MAX485 module converter, are hooked up as follows: 
#define DE 12
#define RE 12
*/

// If you're using ESP32 TTGO board, uncomment the variables defined below
/*
// For hardware serial port (U2_RXD & U2_TXD) 
#define RX 16
#define TX 17
// The Data Enable and Receiver Enable pins of the MAX485 module converter, are hooked up as follows:
#define DE 15
#define RE 15
*/

// If you're using Heltec Wireless Stick Lite board, uncomment the variables defined below
/*
// For hardware serial port (U1_RXD & U1_TXD) 
#define RX 9
#define TX 10
// The Data Enable and Receiver Enable pinsof the MAX485 module converter, are hooked up as follows:
#define DE 15
#define RE 15
*/

ModbusMaster node; // Instantiate ModbusMaster object
uint8_t Result;  
uint8_t Temperature,VWC,EC,Salinity; 

// This callback enables the MAX485 transceiver's Driver Enable pin, and optionally disable its Receiver Enable pin
void preTransmission() {
 digitalWrite(RE, 1);
 digitalWrite(DE, 1);
}

// This callback enables the MAX485 transceiver's Receiver Enable pin, and disable its Driver Enable pin
void postTransmission() {
 digitalWrite(RE, 0);
 digitalWrite(DE, 0);
}

void setup() {
 Serial.begin(9600); // Initialize the serial port with 9600 bauds
 // Configure Data Enable and Receiver Enable pins as outputs 
 pinMode(RE, OUTPUT); 
 pinMode(DE, OUTPUT); 

 // If you're using arduino board, uncomment the line below
 /*
 node.begin(0,Serial); 
 */

 // If you're using LoRa32u4 board, uncomment the two lines below
 /*
 Serial1.begin(9600, SERIAL_8N1);
 node.begin(0,Serial1); 
 */

 // If you're using ESP32 TTGO board, uncomment the two lines below
 /*
 Serial2.begin(9600, SERIAL_8N1, RX, TX);
 node.begin(0,Serial2);
 */

 // If you're using Heltec Wireless Stick Lite board, uncomment the two lines below
 /*
 Serial1.begin(9600, SERIAL_8N1, RX, TX); 
 node.begin(0,Serial1);
 */

 // The callbacks below allow us to configure the MAX485 transceiver module correctly  
 node.preTransmission(preTransmission);
 node.postTransmission(postTransmission);
 // MEC-10 RS485 soil sensor calibration. Uncomment the line that corresponds the type of soil chosen and remove the other lines that are not.
 /*
 node.writeSingleRegister(0x0020,0); // Mineral soil, it is chosen by default
 node.writeSingleRegister(0x0020,1); // Sandy soil
 node.writeSingleRegister(0x0020,2); // Clay
 node.writeSingleRegister(0x0020,3); // Organic soil
 */
 delay(100); // Pause for 100 milliseconds
}

void loop() {
 /* 
 * Read the contents of four registers (temperature register, volumetric water content register, electrical conductivity register and salinity register). 
 * The request specifies the starting register address which is 0x0000, and the number of registers which is 4.    
 */
 Result = node.readHoldingRegisters(0x0000, 4); // Get response for the request. This ModBusMaster method returns 0 on success and exception number on failure
 if ( Result == node.ku8MBSuccess ) {
   Serial.print("Temperature : ");
   Temperature = node.getResponseBuffer(0x0000)/100; // Read the measured value of the temperature in °C    
   Serial.print(Temperature); 
   Serial.println(" °C");
   VWC = node.getResponseBuffer(0x0001)/100; // Read the measured value of the volumetric water content in % 
   Serial.print("VWC : ");
   Serial.print(VWC);
   Serial.println(" %");
   Serial.print("EC : ");
   EC = node.getResponseBuffer(0x0002); // Read the measured value of the electrical conductivity in µS/cm 
   Serial.print(EC);
   Serial.println(" µS/cm");
   Serial.print("Salinity : ");
   Salinity = node.getResponseBuffer(0x0003); // Read the measured value of the salinity in mg/L
   Serial.print(Salinity);
   Serial.println(" mg/L");
 }
 delay(5000); // Read data from MEC-10 RS485 soil sensor every 5 seconds
}
