# How to flash ESP32 wirelessly?
*Tested with both android and laptop*
1. Upload the raw [skeleton code](https://github.com/TUdayKiranReddy/Intro-to-UAV/blob/main/wireless_flashing/skeleton.cpp) to ESP32 with a micro USB cable.
2. Find out the IP of ESP32.
3. Now change the skeleton code for your desired use case **NOTE:- Do not alter functions OTAsetup() or OTAloop(), if modified we will not be able to reupload the code once again wirelessly and have to follow the procedure from Step 1.**
4. Append the following line in platform.ini of your project
```
upload_protocol = espota
```
5. Now upload the bin file OTA(Over The Air)
```
pio run -t upload --upload-port $ESP32_IP
```
