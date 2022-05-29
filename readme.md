# Beryl

Beryl could be the daughter firmware of Azurit and AzuritBer.

## My Objectives
- Learn the software aspects and (hardware) components of the Ardumower platform and C++
- Learn to build and improve functional software for the Ardumower
- Learn how a differential drive robot lawn mower can and should function in the real world that is 'my garden'
- Try to create a functional firmware for the Ardumower that has all the best of both firmwares.
- If I succeed in the above objectives, give the firmware back to the Ardumower community and work together on improving it

To sum this up:
- Learn
- Try
- Improve
- Repeat the above ;-)

## High Level Firmware Objective

Create an Ardumower firmware that:
- [ ] Is modular built, to accomodate multiple hardware platforms
- [ ] Everything is built on the service model
- [ ] Is based on a more robust architecture
  - [ ] [Subsumption](https://en.wikipedia.org/wiki/Subsumption_architecture)
  - [ ] [DAMN](https://en.wikipedia.org/wiki/Distributed_architecture_for_mobile_navigation)
- [ ] Honours perimeter wire boundaries
- [ ] Can mow in lanes
- [ ] Reacts to taller grass situations nicely
- [ ] Tries to avoid an object, and continue it's path
- [ ] Moves in a smooth way
  - [ ] Makes full use of the odometry and sensor capabilities
- [ ] Can get herself out if a miserable situation most of the time
- [ ] Tries to use the shortest path to the charging station as possible
- [ ] Buzzer sounds are recognizable and fun to hear
- [ ] Has App integration (the Ardumower app)
- [ ] Has HomeAssistant integration
  - [ ] To not start mowing if weather conditions are not nice

## My Hardware Platform
In June 2021 I bought a used (and mistreated) Ardumower.
A few repairs on the version 1.3 PCB, a lot of cleaning and re-assembling and I have got a working Ardumower.

Marked means built and connected

- [X] [Ardumower Chassis 2019 edition (I believe)](https://www.marotronics.de/Ardumower-Chassis-Umruest-Set-auf-das-Model-2021-mit-Bumper)
- [x] [Ardumower PCB 1.3](https://www.marotronics.de/Ardumower-Mainboard-13-Der-Konfigurator-fuer-Deinen-Rasenroboter)
- [x] [Arduino Due](https://www.marotronics.de/DUE-Entwicklungsboard-R3-32-Bit-ARM-Cortex-M3-Arduino-Kompatibel)
- [x] [MA42 Brushed wheel motors](https://www.marotronics.de/MA42-DC-Planeten-Getriebemotor-24-Volt-mit-HallIC-30-33-RPM-8mm-Welle-ab-2-Stueck-Staffelpreis)
- [x] [Mowing Motor](https://www.marotronics.de/Maehscheiben-Set-mit-Motor-und-Spanner-fuer-den-Selbstbau-Rasenroboter)
- [x] [Ardumower Switch Bumper](https://www.marotronics.de/ArduMower-Bumper-Nachruest-Kit)
- [x] [DHT11 Temperature Sensor](https://www.marotronics.de/DHT11-Digitaler-Temperatursensor-und-Feuchtigkeitssensor-fuer-Arduino)
- [x] [3x HC-SR04 Ultrasonic module](https://www.marotronics.de/HC-SR04-Ultraschallsensor-Ultrasonic-Ranging-Module)
- [x] [MPU6050/GY-521 IMU](https://www.marotronics.de/3-Achsen-Gy-521-Gyroskop-Accelerometer-MPU-6050-Raspberry-Pi-Arduino)
- [x] [LM2596S Current regulator](https://www.marotronics.de/DC-DC-Spannungsregler-LM2596S-Step-Down-Regler-einstellbar)
- [x] [Rain sensor](https://www.marotronics.de/Regensensor-Modul-YL-38-fuer-Arduino-Raspberry-PI-Regentropfen-Sensor-Naessesensor)
- [ ] [Oled Display](https://www.marotronics.de/096-OLED-Display-Blau-Gelb-I2C-SPI-128x64-SSD1106-fuer-Arduino-Raspberry-Pi)
- [ ] [Neo 6M GPS Module](https://www.marotronics.de/NEO-6M-GPS-Modul-GY-GPS6MV2-NEO-6M-Flight-Controller-zb-fuer-Arduino)

Hardware whishlist:
- [ ] [RFID Reader](https://www.marotronics.de/RFID-Kit-RC522-Mifare-Transponder-Modul-Writer-Reader-fuer-Arduino-Raspberry-1356Mhz)

## Current State

Non working - complete onder development.