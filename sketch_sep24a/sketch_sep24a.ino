#include <Servo.h>

Servo ESC;     // create servo object to control the ESC

int RPM;
int input_RPM;
int max_rpm = 3600;
int max_accel = 1;
  // value from the analog pin

void setup() {
  // Attach the ESC on GPIO pin 5
  Serial.begin(9600);
  input_RPM = 1200;
  ESC.attach(5,1000,2000); // (pin, min pulse width, max pulse width in microseconds) 
}

void loop() {
  // Serial.println("Enter RPM value: ");
  // while (Serial.available() == 0){}
  // RPM = Serial.parseInt();
  // Serial.println("hi");
  // Serial.println(RPM);
  Serial.print("Setting RPM: ");
  Serial.println(input_RPM);
  Serial.println(RPM);

  RPM = map(input_RPM, 0, 3600, 0, 180);   // scale it to use it with the servo library (value between 0 and 3600 rad/s)
  ESC.write(RPM);    // Send the signal to the ESC

  delay(1000);

  RPM = map(0, 0, 3600, 0, 180);   // scale it to use it with the servo library (value between 0 and 3600 rad/s)
  ESC.write(RPM);    // Send the signal to the ESC

  delay(5000);

}
