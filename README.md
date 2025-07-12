# OBSTACLE DETECTION BOT-

**Abstract:**
Obstacle-avoiding robots play a crucial role in autonomous navigation systems used in fields like automation, surveillance, and delivery. This project focuses on building a cost-effective Arduino-powered robot that detects and avoids obstacles using the HC-SR04 ultrasonic sensor. A key challenge in such systems is sensor noise, which can lead to inaccurate distance measurements and unstable robot behavior. To address this, the robot integrates a simple yet effective moving average filter that smooths out fluctuations in the ultrasonic sensor readings, enabling more reliable and consistent obstacle detection.

The robot uses a motor driver to control two DC motors based on filtered sensor input. When an obstacle is detected within a threshold distance, the robot stops and turns to avoid a collision. This behavior is achieved using real-time distance measurements and decision logic coded in Arduino. The entire system is designed for simplicity and educational purposes, serving as a foundational step for more advanced autonomous robotic platforms.

This project demonstrates the integration of basic electronics, filtering algorithms, and control logic to achieve stable and autonomous robot navigation.

