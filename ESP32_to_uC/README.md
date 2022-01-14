# How to flash AVR microController with an ESP32 using ICSP(*In Circuit Serial Programming*) ?
Here ESP32 acts as a SPI MASTER (or PROGRAMMER) and AVR μC acts as a SPI SLAVE (or TARGET) and both are connected by HSPI and ICSP ports.
### Connections
**NOTE:- Since LOGIC HIGH Voltage of ESP32 3.3V, we can do connections only to AVR board which has 3.3V. If AVR's LOGIC HIGH is 5V then we have to use _Voltage Level Shifters_ otherwise we cannot transmit data between these boards.**

+-----------+-------------+
| ESP8266   | AVR / SPI   |
+===========+=============+
| GPIO12    | MISO        |
+-----------+-------------+
| GPIO13    | MOSI        |
+-----------+-------------+
| GPIO14    | SCK         |
+-----------+-------------+
| any\*     | RESET       |
+-----------+-------------+
