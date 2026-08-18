# ESP32 Object Avoidance Robot 🤖

> An autonomous obstacle-avoidance robot built using **ESP32, HC-SR04 ultrasonic sensor, SG90 servo motor, L298N motor driver, and DC geared motors**.

## 🎥 Demo Video

[![ESP32 Object Avoidance Robot - Watch Demo](https://img.shields.io/badge/▶%20Watch%20Demo%20on%20YouTube-red?style=for-the-badge\&logo=youtube)](YOUR_YOUTUBE_VIDEO_LINK_HERE)

**Watch the robot detect obstacles, scan its surroundings, choose the clearer path, and navigate autonomously.**

---

## 📖 Project Overview

This project is an **ESP32-based autonomous object-avoidance robot** designed and built from scratch.

An **HC-SR04 ultrasonic sensor** is mounted on an **SG90 servo motor**, allowing the robot to scan different directions when an obstacle is detected. The ESP32 processes the distance measurements and controls the DC motors through an **L298N motor driver** to select a suitable path.

---

## 📸 Final Prototype

|        Front / Main View       |             Front Sensor Assembly              |
| :----------------------------: | :---------------------------------: |
| ![](Images/Robot-View-IMG.jpg) | ![](Images/Robot-View2-IMG.jpg) |
|       **Complete Robot**       |            **Side View**            |

The final prototype combines the mechanical chassis, drive system, ESP32 controller, motor driver, ultrasonic sensor, servo motor, battery, and wiring into a compact autonomous robot.

---

## Frame View

|        Chassis View       |           Bottom View           |
| :-----------------------: | :--------------------------------: |
| ![](Images/Frame-IMG.jpg) | ![](Images/Frame-Bottom-View-IMG.jpg) |
|     **Custom Chassis**    |       **Top Frame Structure**      |

The robot chassis was manually constructed using lightweight wooden/ice-cream sticks. The frame was designed to provide enough space for the motors, wheels, electronics, battery, and sensor assembly.

---

## ⚙️ Drive System

|              Top Frame View              |              Rear View              |           Robot Top View           |        Side View     |
| :-----------------------------------: | :---------------------------------: | :--------------------------------: | :-----------------------------: |

| ![](Images/Frame-Top-View-IMG.jpg) | ![](Images/Frame-Back-View-IMG.jpg) | ![](Images/Robot-Top-View-IMG.jpg) | ![](Images/Frame-Side-View-IMG.jpg) |
|     **Motor & Wheel Arrangement**     |          **Rear Structure**         |            **Top View**            |     **HC-SR04 + SG90 Servo**    |

Two DC geared motors are used to drive the robot. The motors are mounted on opposite sides and provide differential drive, allowing the robot to move forward, reverse, and turn.

---

## 🔌 Electronics & Wiring

|       Complete Electronics      |    Internal Arrangement    |
| :-----------------------------: | :------------------------: |
| ![](Images/Robot-View2-IMG.jpg) | ![](Images/Frame-IMG2.jpg) |
|    **ESP32 & Sensor System**    |   **Internal Components**  |

The electronics include the **ESP32 development board, L298N motor driver, HC-SR04 ultrasonic sensor, SG90 servo motor, battery, and connecting wires**.

The ESP32 acts as the main controller and coordinates the sensor scanning and motor movement.

---



The **HC-SR04 ultrasonic sensor** measures the distance between the robot and nearby objects.

The sensor is mounted on an **SG90 servo motor**, allowing it to rotate and scan different directions instead of sensing only the area directly in front of the robot.

---

## 🧩 Additional Frame View

|         Frame View         |           Robot View           |
| :------------------------: | :----------------------------: |
| ![](Images/Frame-IMG2.jpg) | ![](Images/Robot-View-IMG.jpg) |
|     **Internal Frame**     |       **Assembled Robot**      |

These views show how the mechanical structure and electronics are integrated into the final prototype.

---

## 🛠️ Components Used

| Component                     | Description                      |
| :---------------------------- | :------------------------------- |
| **ESP32 Development Board**   | Main microcontroller             |
| **L298N Motor Driver**        | Controls the DC motors           |
| **2 × DC Gear Motors**        | Provides robot movement          |
| **HC-SR04 Ultrasonic Sensor** | Measures obstacle distance       |
| **SG90 Servo Motor**          | Rotates the ultrasonic sensor    |
| **2 × 18650 Li-ion Cells**    | Power source                     |
| **Robot Wheels**              | Provides traction and movement   |
| **Custom Chassis**            | Wooden/ice-cream-stick structure |
| **Jumper Wires**              | Electrical connections           |

---

## 🔌 Circuit Connections

| Component           | ESP32 Pin |
| :------------------ | :-------: |
| **Ultrasonic TRIG** |   GPIO 5  |
| **Ultrasonic ECHO** |  GPIO 18  |
| **Motor IN1**       |  GPIO 27  |
| **Motor IN2**       |  GPIO 26  |
| **Motor IN3**       |  GPIO 25  |
| **Motor IN4**       |  GPIO 33  |
| **Servo Signal**    |  GPIO 13  |

---

## 🚀 How It Works

### 1. Forward Motion

The robot continuously measures the distance in front of it.

If the measured distance is greater than **20 cm**, the robot continues moving forward.

### 2. Obstacle Detection

When an obstacle is detected within **20 cm**, the ESP32 stops the motors.

### 3. Direction Scanning

The SG90 servo rotates the HC-SR04 ultrasonic sensor to scan different directions.

The robot checks approximately:

* **Left:** 150°
* **Right:** 30°

### 4. Distance Comparison

The ESP32 compares the measured distances from both directions.

### 5. Path Selection

The robot selects the direction with the greater available distance.

```text
             START
               │
               ▼
        Measure Distance
               │
        ┌──────┴──────┐
        │             │
     > 20 cm       ≤ 20 cm
        │             │
        ▼             ▼
   Move Forward      STOP
                      │
                      ▼
               Scan Left/Right
                      │
                      ▼
              Compare Distance
                      │
             ┌────────┴────────┐
             │                 │
        Left is Clear      Right is Clear
             │                 │
             ▼                 ▼
         Turn Left         Turn Right
             │                 │
             └────────┬────────┘
                      │
                      ▼
                Move Forward
                      │
                      ▼
                Repeat Cycle
```

---

## 💻 Installation & Setup

### 1. Clone the Repository

Clone this repository or download the project files.

### 2. Open the Code

Open the Arduino source file located inside the `Code` folder:

```text
Code/Obstacle_Avoiding_Robot.ino
```

### 3. Install ESP32 Board Support

Open Arduino IDE and install the **ESP32 board package** through the Boards Manager.

### 4. Install ESP32Servo

If the standard `Servo.h` library causes compilation problems with ESP32, install the **ESP32Servo** library through the Arduino IDE Library Manager.

Use:

```cpp
#include <ESP32Servo.h>
```

instead of:

```cpp
#include <Servo.h>
```

### 5. Select Board

Select your appropriate ESP32 board from:

```text
Tools → Board → ESP32
```

### 6. Select COM Port

Connect the ESP32 to your computer and select the correct COM port.

### 7. Upload

Upload the program to the ESP32.

### 8. Test the Robot

Power the robot and place an obstacle in front of it.

The robot should:

1. Move forward.
2. Detect the obstacle.
3. Stop.
4. Scan left and right.
5. Compare the distances.
6. Turn toward the clearer direction.
7. Continue moving forward.

---

## 📁 Project Structure

```text
ESP32-Object-Avoidance-Robot/
│
├── Code/
│   └── Obstacle_Avoiding_Robot.ino
│
├── Images/
│   ├── Frame-Back-View-IMG.jpg
│   ├── Frame-Bottom-View-IMG.jpg
│   ├── Frame-IMG.jpg
│   ├── Frame-IMG2.jpg
│   ├── Frame-Side-View-IMG.jpg
│   ├── Frame-Top-View-IMG.jpg
│   ├── Robot-Top-View-IMG.jpg
│   ├── Robot-View-IMG.jpg
│   └── Robot-View2-IMG.jpg
│
└── README.md
```

---

## ✨ Key Features

* 🤖 ESP32-based autonomous navigation
* 📡 HC-SR04 ultrasonic obstacle detection
* 🔄 SG90 servo-controlled sensor scanning
* 🧭 Automatic path selection
* ⚙️ Dual DC motor drive
* 🔋 Battery-powered operation
* 🛠️ Custom-built lightweight chassis
* 💻 Embedded C/C++ programming
* 🚗 Autonomous obstacle avoidance

---

## 🎯 Applications

This project can be extended for:

* Autonomous mobile robots
* Educational robotics
* Indoor navigation
* Autonomous vehicle prototypes
* Surveillance robots
* Embedded systems experiments
* Robotics research and development

---

## 🔮 Future Improvements

Possible improvements include:

* Add Bluetooth or Wi-Fi remote control
* Add an ESP32-CAM for live video
* Implement PID-based motor control
* Add wheel encoders for accurate movement
* Improve obstacle-avoidance algorithms
* Add mapping and navigation capabilities
* Add a rechargeable battery management system

---

## 🤝 Contributing

Feel free to fork this project, submit pull requests, or suggest improvements to the navigation algorithm.

If you find this project useful, consider giving the repository a ⭐.

---

## 👨‍💻 Author

**Pavan Kalyan Imandi**

Electronics & Communication Engineering | Embedded Systems | Robotics

---

### ⭐ If you like this project, consider giving it a star!
