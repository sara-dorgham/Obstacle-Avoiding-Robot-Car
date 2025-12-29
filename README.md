 🤖 Autonomous Obstacle-Avoiding Robot Car  
A fully autonomous robot car that uses an ultrasonic sensor, servo scanning, and motor control to detect and avoid obstacles in real time.  
Built using Arduino, DC motors, and L298N driver — with a clean, modular code architecture.



🌟 Project Overview
This project demonstrates an autonomous mobile robot capable of detecting obstacles and making real-time movement decisions.  
By combining ultrasonic distance measurement with a servo-mounted scanning system, the robot analyzes its surroundings (left–front–right) and chooses the safest direction to move.

The project focuses on:
- Hardware integration  
- Real-time sensor processing  
- Motor control  
- Autonomous decision-making  



🧩 1. Hardware Components (Detailed Overview)

 🔵 Arduino UNO  
Acts as the brain of the robot.  
Handles:
- Reading ultrasonic sensor data  
- Controlling servo rotation  
- Sending PWM signals to the motor driver  
- Running the obstacle avoidance logic  



🟣 Ultrasonic Sensor (HC-SR04)  
Responsible for measuring distance to obstacles.

How It Works:
1. TRIG sends an ultrasonic pulse.  
2. The pulse bounces back if it hits an object.  
3. ECHO receives the reflected pulse.  
4. The time taken → converted into distance (cm).  

 Pin Connections:
- TRIG → 13  
- ECHO → 12  
- VCC → 5V  
- GND → GND  



🟡 Servo Motor  
The ultrasonic sensor is mounted on a servo to allow **180° scanning**.

Role:
- Scans left, front, and right  
- Helps the robot build a simple understanding of its surroundings  
- Enables smarter obstacle avoidance instead of just bumping into objects  

 Pin:
- Signal → 4  



🔴 L298N Motor Driver  
Controls the speed and direction of both DC motors.

 Right Motor:
- ENA → 5 (PWM)  
- IN1 → 6  
- IN2 → 7  

 Left Motor:
- ENB → 11 (PWM)  
- IN3 → 8  
- IN4 → 9  

 Why L298N?
- Arduino can't drive motors directly  
- Motor driver provides high-current H-bridge control  



🟠 DC Motors + Wheels  
Provide movement.  
Respond to:
- PWM → speed  
- Direction pins → forward/backward/turn  



 ⚫ Power Supply  
- Battery pack powers L298N (motors)  
- Arduino powered via USB or external battery  
- **All grounds must be connected together** to avoid noise issues  



 🔧 2. Wiring Diagram (Text Summary)

| Component | Arduino Pin |
|----------|-------------|
| Ultrasonic TRIG | 13 |
| Ultrasonic ECHO | 12 |
| Servo Signal | 4 |
| Right Motor ENA | 5 |
| Right Motor IN1 | 6 |
| Right Motor IN2 | 7 |
| Left Motor ENB | 11 |
| Left Motor IN3 | 8 |
| Left Motor IN4 | 9 |

Power: 
- Battery → L298N  
- Arduino GND ↔ L298N GND  



 🧠 3. Code Explanation (Descriptive & High-Level)

The software running on the Arduino is structured to be simple, modular, and easy to debug.  
Here’s a breakdown of the logic and purpose of each major component:



🔹 1. Initialization Phase  
At the start, all pins are defined and the servo is attached.  
Motor pins, ultrasonic sensor pins, and PWM outputs are configured, ensuring the robot is ready to read and move instantly.

---

 🔹 2. Distance Measurement System  
A dedicated function handles the ultrasonic sensor logic:

- Sends a trigger pulse  
- Waits for echo return  
- Calculates the distance using the time taken  

This function is called during scanning to measure left, center, and right distances.



 🔹 3. Modular Motor Control  
The movement system is abstracted into functions:
- **forward()**  
- **left()**  
- **right()**  
- **stopCar()**

These functions send organized HIGH/LOW signals to the motor driver + control motor speed through PWM.

This makes the code clean and the main logic very readable.



 🔹 4. Servo-Based Environmental Scanning  
Inside the loop, the servo rotates to three key positions:
- **0° → Left**
- **90° → Center**
- **180° → Right**

At each angle, a distance is measured.  
This creates a simple 3-point “map” that guides the robot’s decisions.



 🔹 5. Decision-Making Algorithm  
After collecting the three distances, the robot chooses the best action:

1. If **front is clear**, it moves forward.  
2. If **front is blocked**, it checks:
   - Is the left side more open?  
   - Or is the right side safer?  

3. It then turns toward the direction with greater free space.

This creates a basic but effective real-time obstacle avoidance system.



 🔹 6. Continuous Autonomous Loop  
The robot continuously repeats:
- Scan environment  
- Measure distance  
- Compare results  
- Adjust movement  

This gives it instant reaction to new obstacles and dynamic behavior.



 🚀 4. How to Run the Project

1. Open Arduino IDE  
2. Load `RobotCar.ino`  
3. Select **Arduino UNO**  
4. Choose the correct COM port  
5. Upload the code  
6. Connect battery to L298N  
7. Place robot on the ground  
8. It will start scanning and moving automatically  



 🔮 5. Future Improvements

- Add IR sensors for line following  
- Add Bluetooth manual-control mode  
- Use PID for smoother turning  
- Replace ultrasonic with LiDAR  
- Upgrade to ESP32 for WiFi/Telemetry  
- Add OLED screen for debugging  



 ⭐ 6. Team Members  

- Team Membe 1: Sara Dorgham
- Team Membe 2:  Youssef Ahmed
- Team Membe 3:   Nada Nabil
- Team Membe 4:  Menna Elasaly
- Team Membe 5:Eman Kilany
- Team Membe 6:  Malak Khaled






