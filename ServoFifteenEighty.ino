#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
// int angle = 0;

void setup() {
  Serial.begin(9600);
  // myservo.attach(12, 500, 2500);  // attaches the servo on pin 0 to the servo object
  myservo.attach(12, 600, 2380);

  // start at 15 degrees. Due to servo orientation, writeAngle = 90 - desiredAngle.
  myservo.write(90-15);

  //wait for any serial message before starting to move
  while (Serial.available() == 0) {
  }

  for (pos = 15; pos <= 80; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Serial.println(pos);
    myservo.write(90-pos);              // tell servo to go to position in variable 'pos'
    delay(123);                       // waits 123 ms for the servo to reach the position. This should work out to be 8 seconds from 15 degrees to 80 degrees
  }
}

void loop() {}
