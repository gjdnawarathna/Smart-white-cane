# ESP32 Ultrasonic Sensor and GPS with Firebase Integration

This project demonstrates how to use an ESP32 board with ultrasonic sensors and a GPS module to detect objects within a certain distance and track the device's location. The data gathered is then sent to a Firebase Realtime Database.

## Hardware Requirements

- ESP32 board
- 2x Ultrasonic Sensors (HC-SR04)
- GPS Module
- Buzzer

## Software Requirements

- Arduino IDE
- FirebaseESP32 library

## Setup

1. **Connect the Hardware**:
   - Connect the ultrasonic sensors to pins 6, 7, 8, and 9 on the ESP32.
   - Connect the buzzer to pin 5.
   - Connect the GPS module to pins 10 and 11 for serial communication.

2. **Install Libraries**:
   - Install the `FirebaseESP32` library in the Arduino IDE.

3. **Configure Firebase**:
   - Go to the [Firebase Console](https://console.firebase.google.com/) and create a new project.
   - Navigate to the "Database" section and create a Realtime Database.
   - Obtain your Firebase project's configuration details (API Key, Auth Domain, etc.) from the project settings.

4. **Update the Code**:
   - Replace the placeholders in the code with your WiFi credentials and Firebase project settings.

## Usage

- Upload the code to your ESP32 board using the Arduino IDE.
- The ESP32 will start measuring distances with the ultrasonic sensors and tracking its location with the GPS module.
- If an object is detected within 150 cm by either sensor, the buzzer will play a 1000 Hz tone.
- The sensor data and GPS location are sent to the Firebase Realtime Database every 10 seconds.

## Firebase Integration

- The data sent to Firebase includes the distances measured by the ultrasonic sensors and the GPS coordinates.
- You can view and manipulate this data through the Firebase Console or by using the Firebase JavaScript SDK in a web application.

## Contributing

Feel free to contribute to this project by submitting pull requests or reporting issues.

## License

This project is licensed under the MIT License.
