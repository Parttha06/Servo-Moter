#include <Servo.h>

Servo servo1; // Create object for Servo motor 1
int angle = 0; // Variable to store the position

void setup() {
  servo1.attach(9); // Attach servo to pin 9
}
void loop() {
  int potValue = analogRead(A0); // Read the analog value from potentiometer
  angle = map(potValue, 0, 1023, 0, 180); // Convert analog value to servo angle range
  servo1.write(angle); // Set servo position
  delay(15); // Delay for stability
}