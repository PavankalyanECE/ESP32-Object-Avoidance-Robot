# ESP32 Object Avoidance Robot 🤖

An autonomous object-avoidance robot powered by an **ESP32**. The robot uses an **HC-SR04 ultrasonic sensor mounted on an SG90 servo motor** to scan its surroundings, detect obstacles, and navigate toward the clearest path.

---

## 📸 Project Build

### 🏗️ Custom Chassis

<table>
  <tr>
    <td align="center">
      <img src="Images/Frame-IMG.jpg" width="400">
    </td>
    <td align="center">
      <img src="Images/Frame-Side-View-IMG.jpg" width="400">
    </td>
  </tr>
  <tr>
    <td align="center"><b>Front Frame View</b></td>
    <td align="center"><b>Side Frame View</b></td>
  </tr>
  <tr>
    <td align="center">
      Custom-built lightweight chassis made using wooden/ice-cream sticks.
    </td>
    <td align="center">
      Side structure supporting the wheels and internal components.
    </td>
  </tr>
</table>

---

### ⚙️ Drive System

<table>
  <tr>
    <td align="center">
      <img src="Images/Frame-Bottom-View-IMG.jpg" width="400">
    </td>
    <td align="center">
      <img src="Images/Frame-Back-View-IMG.jpg" width="400">
    </td>
  </tr>
  <tr>
    <td align="center"><b>Bottom View</b></td>
    <td align="center"><b>Rear View</b></td>
  </tr>
  <tr>
    <td align="center">
      Two DC geared motors are mounted on opposite sides to provide differential drive.
    </td>
    <td align="center">
      Rear structure showing the motor and wheel mounting arrangement.
    </td>
  </tr>
</table>

---

### 🔌 Electronics & Wiring

<table>
  <tr>
    <td align="center">
      <img src="Images/Robot-View-IMG.jpg" width="400">
    </td>
    <td align="center">
      <img src="Images/Robot-View2-IMG.jpg" width="400">
    </td>
  </tr>
  <tr>
    <td align="center"><b>Complete Robot</b></td>
    <td align="center"><b>Electronics & Sensor</b></td>
  </tr>
  <tr>
    <td align="center">
      Complete assembled robot with the ESP32, motors, sensor and custom chassis.
    </td>
    <td align="center">
      ESP32 controller, L298N motor driver, HC-SR04 ultrasonic sensor and SG90 servo.
    </td>
  </tr>
</table>

---

### 🔋 Internal Arrangement

<table>
  <tr>
    <td align="center">
      <img src="Images/Frame-IMG2.jpg" width="400">
    </td>
    <td align="center">
      <img src="Images/Frame-Top-View-IMG.jpg" width="400">
    </td>
  </tr>
  <tr>
    <td align="center"><b>Internal Components</b></td>
    <td align="center"><b>Top Frame View</b></td>
  </tr>
  <tr>
    <td align="center">
      Internal arrangement of the motors, battery, wiring and electronic components.
    </td>
    <td align="center">
      Top structure of the custom-built chassis and component mounting arrangement.
    </td>
  </tr>
</table>

---

### 📡 Sensor System

<table>
  <tr>
    <td align="center">
      <img src="Images/Robot-Top-View-IMG.jpg" width="400">
    </td>
    <td align="center">
      <img src="Images/Robot-View2-IMG.jpg" width="400">
    </td>
  </tr>
  <tr>
    <td align="center"><b>Top View</b></td>
    <td align="center"><b>Ultrasonic Sensor</b></td>
  </tr>
  <tr>
    <td align="center">
      Overall layout of the robot and its sensor assembly.
    </td>
    <td align="center">
      HC-SR04 mounted on an SG90 servo for directional obstacle scanning.
    </td>
  </tr>
</table>

---

## 🎥 See It in Action

Check out the complete DIY build process, including **assembly, wiring, testing, and demonstration**, on **Kalyan Xperiments**:

[![Watch on YouTube](https://img.shields.io/badge/YouTube-Watch_Video-red?style=for-the-badge\&logo=youtube)](YOUR_YOUTUBE_VIDEO_LINK_HERE)

---

## 🛠️ Components Used

| Component                     | Description                             |
| :---------------------------- | :-------------------------------------- |
| **ESP32 Development Board**   | Main microcontroller                    |
| **L298N Motor Driver**        | Controls the DC motors                  |
| **2 × DC Gear Motors**        | Provides robot movement                 |
| **HC-SR04 Ultrasonic Sensor** | Detects obstacles and measures distance |
| **SG90 Servo Motor**          | Rotates the ultrasonic sensor           |
| **Battery Pack**              | Provides power to the robot             |
| **Robot Wheels**              | Provides movement and traction          |
| **Custom Chassis**            | Wooden/ice-cream-stick structure        |
| **Jumper Wires**              | Electrical connections                  |

---

## 🔌 Circuit Connections

| Component           | ESP32 Pin |
| :------------------ | :-------- |
| **Ultrasonic TRIG** | GPIO 5    |
| **Ultrasonic ECHO** | GPIO 18   |
| **Motor IN1**       | GPIO 27   |
| **Motor IN2**       | GPIO 26   |
| **Motor IN3**       | GPIO 25   |
| **Motor IN4**       | GPIO 33   |
| **Servo Signal**    | GPIO 13   |

---

## 🚀 How It Works

### 1. Forward Motion

The robot moves forward while the ultrasonic sensor detects a clear path with a distance greater than **20 cm**.

### 2. Obstacle Detection

When an obstacle is detected within **20 cm**, the ESP32 stops the motors to prevent a collision.

### 3. Sensor Scanning

The SG90 servo rotates the HC-SR04 ultrasonic sensor to scan different directions.

The robot checks:

* **Left side:** approximately 150°
* **Right side:** approximately 30°

The ultrasonic sensor measures the available distance in each direction.

### 4. Decision Making

The ESP32 compares the left and right distance measurements.

* If the **left side** has more space → the robot turns left.
* If the **right side** has more space → the robot turns right.

### 5. Autonomous Navigation

After avoiding the obstacle, the robot resumes forward movement and continues scanning for new obstacles.

---

## 🧠 Control Logic

```text
              START
                │
                ▼
        Measure Front Distance
                │
        ┌───────┴────────┐
        │                │
   Distance > 20 cm   Distance ≤ 20 cm
        │                │
        ▼                ▼
     Move Forward       STOP
                         │
                         ▼
                  Scan Left & Right
                         │
                         ▼
                 Compare Distances
                         │
              ┌──────────┴──────────┐
              │                     │
        Left is Clearer        Right is Clearer
              │                     │
              ▼                     ▼
          Turn Left             Turn Right
              │                     │
              └──────────┬──────────┘
                         │
                         ▼
                   Move Forward
                         │
                         ▼
                  Continue Scanning
```

---

## 💻 Installation & Setup

### 1. Clone the Repository

Clone this repository or download the project files.

### 2. Open the Code

Open:

```text
Code/Obstacle_Avoiding_Robot.ino
```

using the **Arduino IDE**.

### 3. Install ESP32 Board Package

Make sure the ESP32 board package is installed through the Arduino IDE Boards Manager.

### 4. Install ESP32Servo

If the standard `Servo.h` library causes compilation problems on ESP32, install the **ESP32Servo** library from the Arduino IDE Library Manager.

Use:

```cpp
#include <ESP32Servo.h>
```

instead of:

```cpp
#include <Servo.h>
```

### 5. Select Board and Port

Select the appropriate ESP32 board and the correct COM port.

### 6. Upload

Connect the ESP32 to your computer and upload the program.

### 7. Test

Power the robot and place an obstacle in front of it. The robot should detect the obstacle, scan both directions, select the clearer path, and continue moving.

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

* 🤖 ESP32-based autonomous robot
* 📡 HC-SR04 ultrasonic obstacle detection
* 🔄 Servo-controlled sensor scanning
* 🧭 Automatic path selection
* ⚙️ Dual DC motor differential drive
* 🔋 Battery-powered operation
* 🛠️ Custom-built lightweight chassis
* 💻 Embedded C/C++ programming
* 🚗 Autonomous obstacle avoidance

---

## 🎯 Applications

The basic obstacle-avoidance concept can be extended to:

* Autonomous mobile robots
* Indoor navigation robots
* Smart surveillance platforms
* Educational robotics projects
* Autonomous vehicle prototypes
* Robotics and embedded-systems experiments

---

## 🤝 Contributing

Feel free to fork this project, submit pull requests, or suggest improvements to the navigation algorithm.

If you find this project useful, consider giving the repository a ⭐.

---

## 👨‍💻 Author

**Pavan Kalyan Imandi**

Built as a hands-on **ESP32, Embedded Systems, Robotics, and Autonomous Navigation** project.
