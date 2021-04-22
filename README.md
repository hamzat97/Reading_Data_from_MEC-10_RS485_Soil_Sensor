# Reading_Data_from_MEC-10_RS485_Soil_Sensor
This simple work will allow you to know how to read data from MEC-10 RS485 soil sensor using some development boards which are compatible with the Arduino IDE. This sensor is widely applicable for science research, irrigation, greenhouse and smart agriculture. MEC-10 measures volumitric water content (VWC), soil temperature, soil electrical conductivity (EC) and soil salinity. The output signal of this sensor can be RS485, analog voltage or analog current, but in this work, we will just focus on the first one which uses the RS485 serial transmission standard.

Boards Supported:

- Arduino Boards
- LoRa32u4 Boards 
- ESP32 TTGO Boards
- Heltec Wireless Stick Lite Boards

## What do you need ?
First of all, you will need a TTL/RS485 converter module to ensure communication between the microcontroller and the sensor. The MAX485 converter module is the one used in this work, you can [buy it here](https://fr.aliexpress.com/item/32727897752.html?spm=a2g0o.search0302.0.0.215b4a68NXJvne&algo_pvid=7cd7a219-c649-4072-a508-f45c0599361b&algo_expid=7cd7a219-c649-4072-a508-f45c0599361b-14&btsid=0b0a556116189643503323911e8124&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_) from AliExpress.
## Arduino Setup
### Add Modbus Library in Arduino IDE
Most RS485 devices use Modbus, and the MEC-10 RS485 soil sensor also uses this serial communication protocol which is widely used by industrial electronic devices. This is the reason why you will need to install the ModbusMaster library through which to access the sensor configuration and read the measurements.
### Install LoRa32u4 in Arduino IDE
First, you have to install adafruit driver (adafruit_drivers.exe in LoRa32u4II software folder) if you're running Windows on your computer in order to be able to upload the sketch to LoRa32u4 II using the mini USB cable. On the other hand, you don't have to install this driver if you're using a Linux computer. Second, you should copy the content of hardware folder (in LoRa32u4II software folder) into Documents/Arduino/hadrware folder, and if this last one doesn't already exist, so just copy hardware folder into Documents/Arduino, where libraries folder does exist.
### Install ESP32 in Arduino IDE
Just visit this [link](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/) and you will know how to install ESP32 in Arduino IDE whether you’re using Windows, Mac OS X or Linux. 
### Install Heltec ESP32 in Arduino IDE
Just visit this [link](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/) and you will know how to install Heltec ESP32 in Arduino IDE using one of two possible methods.
## MEC-10 RS458 Soil Sensor Calibration
MEC-10 RS458 can be software calibrated for specific soils (sandy soil, clay soil, mineral soil and organic soil), knowing that it is calibrated for mineral soil by default. The Arduino sketch explains how to easily define the type of soil to calibrate the sensor. 

***Some Important Notes:***
- The arduino sketch will not even be compiled if you don't uncomment a few blocks. Before everything, you need to read the comments carefully to know which lines must be uncommented, it all depends on the board you're using in your application.
- Carry out the wiring as represented in the description (images in the Wiring Diagram folder) and do not connect SET pin of the sensor to the ground (V-) in setup mode.
- The correct sensor installation should be your top priority, this is is why reading the user manual is strongly recommended. 

Finally, I remain at your entire disposal for any further information, just contact me at my academic mail h.taous@ump.ac.ma if you have any questions or if you need any kind of assistance.
