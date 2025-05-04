# 🏠✨ Home Automation System with Dual Arduino Setup

This project implements a home automation system using two Arduinos. The first Arduino collects sensor data (motion and temperature), and the second Arduino controls a relay and displays information on an LCD. The two Arduinos communicate via serial protocol.

## ✨ Features

- 🔍 **Arduino 1 (Sensors)**:
  - 🕵️ Detects motion using a PIR sensor.
  - 🌡️ Measures temperature using an LM35 sensor.
  - 📨 Sends data (`motion,temperature`) via serial communication.

- 💡 **Arduino 2 (Control and Display)**:
  - 📬 Receives data from Arduino 1.
  - 🖥️ Displays motion status and temperature on a 20x4 I2C LCD.
  - ⚡ Controls a relay to activate a fan based on the temperature.

- 🔄 **Fallback Mode**:
  - 🚨 If no serial data is received, the system switches to simulated data for testing and fallback operation.

## 🛠️ Components Used

### Arduino 1
- 🤖 Arduino Uno
- 🔧 PIR motion sensor (HC-SR501)
- 🌡️ Temperature sensor (LM35)
- 🔌 Connecting wires

### Arduino 2
- 🤖 Arduino Uno
- 🖥️ 20x4 I2C LCD
- ⚡ Relay module
- 🔌 Connecting wires
- 🔲 Resistors (10kΩ recommended for pull-down on PIR)
