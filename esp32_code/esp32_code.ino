#include <WiFi.h>
#include <FirebaseESP32.h>

// WiFi credentials
const char* ssid = "janith";
const char* password = "janith123";

// Firebase project settings
#define FIREBASE_HOST "https://smart-white-cane-b7d7c-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "AIzaSyAujCstGsE3qnZRCOCZr3XcCJEHTjJb-mQ"

// Initialize FirebaseESP32 object
FirebaseData firebaseData;

void setup() {
 Serial.begin(115200);

 // Connect to WiFi
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
 }
 Serial.println("WiFi connected");

 // Initialize Firebase
 Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
 Firebase.reconnectWiFi(true);
}

void loop() {
 // Example data to send
 String path = "/sensorData";
 String data = "{\"distance1\": 150, \"distance2\": 150, \"latitude\": 37.7749, \"longitude\": -122.4194}";

 // Send data to Firebase
 if (Firebase.setString(firebaseData, path, data)) {
    Serial.println("Data sent successfully");
 } else {
    Serial.println("Failed to send data");
    Serial.println(firebaseData.errorReason());
 }

 delay(10000); // Wait for 10 seconds before sending the next data
}
