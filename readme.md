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
