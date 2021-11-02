#include <NewPing.h>
#include <AccelStepper.h>
#define motorPin1 8
#define motorPin2 9
#define motorPin3 10
#define motorPin4 11
#define MotorInterfaceType 8
AccelStepper stepper = AccelStepper(MotorInterfaceType,
motorPin1, motorPin3, motorPin2, motorPin4);

#define TRIGGER_PIN 2  // sensor ultrasonic luar
#define ECHO_PIN 3 
#define MAX_DISTANCE 8

#define TRIGGER_PIN1 5 // sensor ultrasonic dalam
#define ECHO_PIN1 6 
#define MAX_DISTANCE1 8

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE1);

void setup() {
Serial.begin(9600);
stepper.setMaxSpeed(1000);
stepper.setAcceleration(900);
}

void loop() {
delay(50);
int luar = sonar.ping_cm(); 
int dalam = sonar1.ping_cm(); 
Serial.print("luar : "); Serial.println(luar);
Serial.print("dalam : "); Serial.println(dalam);

if((luar>0)||(dalam>0))
{ stepper.runToNewPosition(5500);  // buka pintu
}
else 
{ stepper.runToNewPosition(0);  // tutup pintu 
}
delay(1000);
}
