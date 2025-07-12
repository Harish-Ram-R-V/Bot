# OBSTACLE DETECTION BOT-

**Objective**
The objective of this project is to build an Arduino-based robot that can detect and avoid obstacles using ultrasonic sensing, and improve its accuracy by implementing a median filter.
The robot should make movement decisions based on noise-filtered sensor input to avoid erratic behavior caused by outlier data.


**Abstract:**
In real-time robotic applications, obstacle avoidance is a critical feature, especially in autonomous systems deployed in dynamic environments such as delivery, surveillance, and smart mobility.
This project presents the design and implementation of an Arduino-based obstacle-avoiding robot that utilizes an HC-SR04 ultrasonic sensor for distance measurement.
A significant challenge addressed in this system is the presence of noisy or spurious readings from the ultrasonic sensor, which can compromise navigation stability and response accuracy.

To enhance the reliability of sensor data, a Median Filter is applied to a rolling buffer of recent distance measurements. Unlike simple averaging methods,
the median filter effectively removes outlier values caused by environmental reflections or sensor glitches, leading to robust and noise-resistant decision-making.
Based on the filtered output, the robot dynamically adjusts its movement—continuing forward if the path is clear or executing an evasive turn when an obstacle is detected within a predefined threshold.

The system integrates core concepts of embedded programming, digital signal processing (filtering), and real-time motor control using a motor driver module.
The result is a smooth-operating robot capable of avoiding collisions with improved stability compared to systems using raw or average sensor data.

This implementation serves as an educational prototype and a baseline model for more advanced autonomous robots incorporating sensor fusion and path planning.


**Results and Observations**
The median filter significantly improved the robot's stability. In scenarios with reflective surfaces or sudden noise spikes, the unfiltered robot showed jittery behavior, while the filtered version maintained a consistent path. The robot responded reliably to obstacles and executed turning maneuvers with better timing and precision.


**Future Work**
  - Integrating multiple ultrasonic sensors for 180° coverage
  - Adding PID-based motor speed control for smoother movement
  - Using Bluetooth or Wi-Fi modules for remote control and data logging
  - Implementing SLAM (Simultaneous Localization and Mapping) using advanced sensor fusion techniques
