# 🖐️ Hand Gesture Recognition Glove

A low-cost embedded system project that translates human hand gestures into meaningful text messages using flex sensors, Arduino, and an 8051 microcontroller. This system enables real-time wireless communication via Bluetooth and is especially useful for assistive communication.

---

## 📌 Overview

The Hand Gesture Recognition Glove captures finger movements using flex sensors and converts them into digital signals. These signals are processed to identify predefined gestures such as *Hello*, *Peace*, and *Okay*, which are then transmitted to a smartphone via Bluetooth.

---

## 🎯 Objectives

- Develop a wearable gesture recognition system
- Enable real-time gesture-to-text communication
- Use cost-effective embedded components
- Assist communication for differently-abled individuals
- Implement reliable gesture classification using sensor thresholds

---

## ⚙️ System Architecture

```
Flex Sensors → Arduino (ADC) → 8051 Microcontroller → HC-05 Bluetooth → Mobile Device
```

---

## 🔧 Hardware Components

| Component | Description |
|----------|------------|
| Flex Sensors (5x) | Detect finger bending |
| Arduino UNO/Nano | Converts analog signals to digital (ADC) |
| 8051 Microcontroller | Processes data and classifies gestures |
| HC-05 Bluetooth Module | Wireless communication |
| Power Supply | 5V battery/USB |
| Glove | Wearable base |

---

## 💻 Software Used

- Keil µVision (8051 programming)
- Arduino IDE
- Embedded C
- Serial Communication (UART)

---

## 🧠 Working Principle

1. Flex sensors change resistance based on finger bending
2. Arduino reads analog values (0–1023)
3. Data is sent via UART to 8051
4. 8051 classifies gestures using threshold logic
5. Recognized gesture is sent via Bluetooth
6. Output is displayed on a smartphone

---

## ✋ Gesture Mapping

| Gesture | Sensor Condition | Output |
|--------|----------------|--------|
| All fingers open | All values < 1020 | Hello |
| Two fingers up | Mixed thresholds | Peace |
| Thumbs up | Specific pattern | Okay |
| Unknown | Any other pattern | Unknown |

---

## 📊 Results

- ✅ Accuracy: ~95%
- ⚡ Real-time communication with minimal delay
- 🔁 Reliable and stable performance
- 📱 Wireless output via Bluetooth

---

## 💰 Cost Analysis

| Component | Cost (INR) |
|----------|-----------|
| 8051 Development Board | 700 |
| HC-05 Bluetooth Module | 345 |
| Flex Sensors | 1000 |
| ISP Programmer | 400 |
| Arduino UNO | 500 |
| Misc (wires, breadboard) | 200 |
| Glove | 100 |
| **Total** | **3245 INR** |

---

## 🚀 Applications

- Assistive technology for speech/hearing impaired
- Human-Computer Interaction (HCI)
- Robotics control
- Smart home automation
- Gaming and VR systems

---

## 🔮 Future Enhancements

- Add more gestures and dynamic motion detection
- Integrate Machine Learning for adaptive recognition
- Develop mobile app interface
- Add Text-to-Speech (TTS)
- Upgrade to ESP32 / ARM-based controllers
- Improve power efficiency and compactness

---

## 🎥 Demo

[Project Demo Video](https://youtu.be/IW1-J7IxoMY?si=-6r3k7eYO37oTRdY)

---


## 📌 Conclusion

This project demonstrates that sensor-based gesture recognition can be implemented efficiently using low-cost embedded systems. It provides a strong foundation for future developments in assistive technology, IoT, and human-machine interaction.

---
