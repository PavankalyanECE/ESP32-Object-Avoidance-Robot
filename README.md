# ESP32 Object Avoidance Robot 🤖

An autonomous object-avoidance robot powered by an ESP32. This robot uses an ultrasonic sensor mounted on a servo motor to scan its surroundings, detect obstacles, and navigate around them by choosing the clearest path.

## 🎥 See it in Action
Check out the full DIY build process, including detailed table recording footage of the assembly and testing, on **Kalyan Tech-hub**:
[![Watch on YouTube](https://img.shields.io/badge/YouTube-Watch_Video-red)](YOUR_YOUTUBE_VIDEO_LINK_HERE)

## 🛠️ Components Used
* **Microcontroller:** ESP32 Development Board
* **Motor Driver:** L298N (or similar)
* **Motors:** 2x or 4x DC Gear Motors
* **Sensor:** HC-SR04 Ultrasonic Distance Sensor
* **Actuator:** SG90 Micro Servo Motor
* **Power:** Battery pack (e.g., 2x 18650 Li-ion cells)
* Chassis, jumper wires, and wheels.

## 🔌 Circuit Connections (Pin Mapping)

| Component | ESP32 Pin |
| :--- | :--- |
| **Ultrasonic TRIG** | GPIO 5 |
| **Ultrasonic ECHO** | GPIO 18 |
| **Motor IN1** | GPIO 27 |
| **Motor IN2** | GPIO 26 |
| **Motor IN3** | GPIO 25 |
| **Motor IN4** | GPIO 33 |
| **Servo Signal** | GPIO 13 |

## 🚀 How It Works
1. **Forward Motion:** The robot moves forward as long as the path ahead is clear (distance > 20 cm).
2. **Obstacle Detection:** If an obstacle is detected within 20 cm, the robot stops.
3. **Scanning:** The servo motor sweeps the ultrasonic sensor to the left (150°) and right (30°) to measure distances.
4. **Decision Making:** The robot compares the left and right distances, turns toward the side with the most open space, and resumes forward motion.

## 💻 Installation & Setup
1. Clone this repository or download the source code.
2. Open the `.ino` file in the Arduino IDE.
3. Ensure you have the ESP32 board package installed in your Boards Manager.
4. *Note:* If you experience compilation issues with the standard `Servo.h` library on the ESP32, install the **ESP32Servo** library from the Library Manager and change `#include <Servo.h>` to `#include <ESP32Servo.h>`.
5. Connect your ESP32, select the correct COM port, and click **Upload**.

## 🤝 Contributing
Feel free to fork this project, submit pull requests, or send suggestions to improve the navigation logic!
