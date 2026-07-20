# Multi-Stage-Security-System
An IoT-based multi-stage security system using Arduino and NodeMCU featuring intrusion detection, fire detection, LCD monitoring, and real-time mobile alerts.

What is a Multi-Stage Security System?
<img width="3060" height="4080" alt="20260405_233612" src="https://github.com/user-attachments/assets/e2af4551-ead7-4f51-961b-5a351e64f0a9" />


An IoT-based smart security system designed using Arduino UNO and NodeMCU to provide real-time intrusion and fire detection with local display and mobile alerts.
Here what we exactly did is combining two security system pipeline and then combining them together to form a system which provides a multi stage security. Here the 
system is the combination has a nodemcu and audrino uno.

The uno here has powers a pir sensor, so whenever an object is detected nearby through it it will pass signal throught the audrino uno and then the data is procedssed and the calculated distance is send to the lcd display.
When the distance between the pir sensor and object is less than 15cm as per the level of the project, an alert is send to the 16*2 display as well as the serial monitor of the IDE. here the system in real world implementation could be used for the protection and real world intrusion detection.

Next the system has the nodemcu which will be acting as the medium for providing the fire alert. Here what we do it that using nodemcu and providing local connection to the computer, nodemcu using the wifi we have also installed  led and buzzer for local level alert. next a remote alert is also provided for distant user. So basically at a time there are two types of security is provided. 

At the first level, we have the security for local alert in form of buzzer, and led alert
next for the remote alert using the Blynk app we provide alert to the user  via the phone app. As the nodemcu and the computer are powered an online detection is found on the nodemcu blynk application. Next in case of an alert i.e in case of detection of fire, an alert is send to the user.
## 🚀 Features

### 🚨 Intrusion Detection Analysis
- PIR sensor for motion detection
- Ultrasonic sensor for object proximity detection
- Multi-stage alert logic
- LCD status display

### 🔥 Fire Detection 
- Flame sensor based fire monitoring
- Instant warning alerts
- IoT-based notification system

### 📱 Smart Notifications
- Telegram / mobile alert support
- Real-time monitoring
- Expandable IoT architecture
  ( here differnet types of notification alert can be provided depending on what user wants) 

### 🖥️ Display System
- 16x2 LCD live status updates
- Displays:
  - Area Safe
  - Motion Detected
  - Object Detected
  - Intruder Alert
  - Fire Alert

---

## 🛠️ Hardware Components

### Intrusion Detection Module
- Arduino UNO
- PIR Sensor
- HC-SR04 Ultrasonic Sensor
- 16x2 LCD Display

### Fire Detection Module
- NodeMCU ESP8266
- Flame Sensor

---

## ⚙️ Technologies Used

- Arduino IDE
- Embedded C/C++
- IoT Communication
- Telegram Bot API
- Sensor Fusion Logic

---

## 🔌 Working Principle

The system works in multiple stages:

1. PIR sensor detects motion
2. Ultrasonic sensor checks distance variation
3. If both conditions are satisfied:
   - Intruder alert is triggered
   - LCD displays warning
   - Mobile notification can be sent

The fire module independently monitors flame detection and sends emergency alerts.

<img width="4080" height="3060" alt="20260414_150314" src="https://github.com/user-attachments/assets/9e0b8c62-0115-4927-bf9d-025d48f75080" />



---

## 📷 Future Improvements

- Camera integration
- GSM alerts
- Cloud dashboard
- Mobile application
- Face recognition
- Smoke and gas sensors

---

## 🎯 Applications

- Smart homes
- Offices
- Laboratories
- Warehouses
- Hostel security systems

---

Author

Sejal Pandey 
Share your build! lets make learning fun and build solutions for my, your and everyone need!
happy learning!!!
