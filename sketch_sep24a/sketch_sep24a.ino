#include <Servo.h>
#define MIN_PULSE_LENGTH 1000 // Minimum pulse length in µs
#define MAX_PULSE_LENGTH 2000 // Maximum pulse length in µs

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
  Serial.print("Setting RPM: ");
  Serial.println(input_RPM);
  Serial.println(RPM);
  Serial.parseInt();

  RPM = map(input_RPM, 0, 3600, 0, 180);   // scale it to use it with the servo library (value between 0 and 3600 rad/s)
  ESC.write(RPM);    // Send the signal to the ESC

  delay(1000);

  RPM = map(0, 0, 3600, 0, 180);   // scale it to use it with the servo library (value between 0 and 3600 rad/s)
  ESC.write(RPM);    // Send the signal to the ESC

  delay(5000);
    if (Serial.available()) {
        RPM = Serial.read();

        switch (RPM) {
            // 0
            case 48 : Serial.println("Sending minimum throttle");
                      ESC.writeMicroseconds(MIN_PULSE_LENGTH);
            break;

            // 1
            case 49 : Serial.println("Sending maximum throttle");
                      ESC.writeMicroseconds(MAX_PULSE_LENGTH);
            break;

            // 2
            case 50 : Serial.print("Running test in 3");
                      delay(1000);
                      Serial.print(" 2");
                      delay(1000);
                      Serial.println(" 1...");
                      delay(1000);
            break;
        }
    }
}
