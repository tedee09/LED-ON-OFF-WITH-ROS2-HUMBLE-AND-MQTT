# MQTT LED Controller with ESP8266 and ROS 2 Humble

This project demonstrates how to control an LED using MQTT with ESP8266 and integrate it with ROS 2 Humble.

## Project Structure
- `arduino/`: Contains the Arduino code for ESP8266.
- `ros2_ws/`: ROS 2 workspace with custom nodes for MQTT control.
- `.gitignore`: Excludes unnecessary files from the repository.

## Requirements
- ROS 2 Humble on Ubuntu 22.04
- Arduino IDE with ESP8266 core
- Mosquitto MQTT Broker

## How to Use
1. Upload the Arduino code from `arduino/` to the ESP8266.
2. Run the ROS 2 node from `ros2_ws/`.
3. Publish MQTT messages to control the LED.

## Acknowledgments
Thanks to the ROS 2 and Arduino communities for their awesome tools and libraries.

## Note Perintah
1. Periksa Alamat IP Komputer
```
hostname -I
```
2. Cek Broker MQTT Berjalan di komputer
```
sudo systemctl start mosquitto
```
3. Verifikasi bahwa broker aktif dan mendengarkan pada port 1883
```
sudo lsof -i :1883
```
Jika terlihat seperti *:1883 (LISTEN), broker sudah siap menerima koneksi.
4. topik untuk menyalakan led esp8266
```
mosquitto_pub -h <IP_BROKER> -t esp8266/led -m "ON"
```
5. topik untuk mematikan led esp8266
```
mosquitto_pub -h <IP_BROKER> -t esp8266/led -m "OFF"
```
6. cek subscriber MQTT di komputer untuk melihat aktivitas topik
```
mosquitto_sub -h 192.168.48.247 -t esp8266/led
```