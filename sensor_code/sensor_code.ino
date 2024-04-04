#include <TinyGPS++.h>
#include <SoftwareSerial.h>

// Ultrasonic Sensor Pins
const int TRIG_PIN_1 = 6;
const int ECHO_PIN_1 = 7;
const int TRIG_PIN_2 = 8;
const int ECHO_PIN_2 = 9;

// Buzzer Pin
const int BUZZER_PIN = 5;

// GPS Module Pins
const int RX_PIN = 10;
const int TX_PIN = 11;

// Create a TinyGPS++ object
TinyGPSPlus gps;

// Create a SoftwareSerial object for GPS
SoftwareSerial gpsSerial(RX_PIN, TX_PIN);

void setup() {
 pinMode(TRIG_PIN_1, OUTPUT);
 pinMode(ECHO_PIN_1, INPUT);
 pinMode(TRIG_PIN_2, OUTPUT);
 pinMode(ECHO_PIN_2, INPUT);
 pinMode(BUZZER_PIN, OUTPUT);

 // Start the GPS serial communication
 gpsSerial.begin(9600);
 Serial.begin(9600);
}

void loop() {
 // Ultrasonic Sensor 1
 long duration1, distance1;
 // Ultrasonic Sensor 2
 long duration2, distance2;

 // Ultrasonic Sensor 1 Measurement
 digitalWrite(TRIG_PIN_1, LOW);
 delayMicroseconds(2);
 digitalWrite(TRIG_PIN_1, HIGH);
 delayMicroseconds(10);
 digitalWrite(TRIG_PIN_1, LOW);
 duration1 = pulseIn(ECHO_PIN_1, HIGH);
 distance1 = (duration1 / 2) / 29.1;

 // Ultrasonic Sensor 2 Measurement
 digitalWrite(TRIG_PIN_2, LOW);
 delayMicroseconds(2);
 digitalWrite(TRIG_PIN_2, HIGH);
 delayMicroseconds(10);
 digitalWrite(TRIG_PIN_2, LOW);
 duration2 = pulseIn(ECHO_PIN_2, HIGH);
 distance2 = (duration2 / 2) / 29.1;

 // Check if either sensor detects an object within 20 cm
 if (distance1 <= 150 || distance2 <= 150) {
    tone(BUZZER_PIN, 1000); // Play a 1000 Hz tone on the buzzer
    delay(100); // Delay to allow the tone to play
 } else {
    noTone(BUZZER_PIN); // Stop the tone if no object is detected
 }

 // GPS Reading
 while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
 }

 if (gps.location.isValid()) {
    Serial.print("Latitude: ");
    Serial.println(gps.location.lat(), 6);
    Serial.print("Longitude: ");
    Serial.println(gps.location.lng(), 6);
 }
}
