/*
  sample program for AccelStepper.h
  inspired by the Bounce example of the Arduino version


*/
#include "AccelStepper.h"

/**
*** Main function
**/

AccelStepper stepper1(1, LED1, LED2); 
AccelStepper stepper2(1, LED3, LED4); 
Timer t;

int main() 
{
  t.start();
  stepper1.setMaxSpeed(10);
  stepper1.setAcceleration(3);
  stepper1.moveTo(50);
  stepper1.setMinPulseWidth(200);
  stepper2.setMaxSpeed(100);
  stepper2.setAcceleration(30);
  stepper2.moveTo(3000);
  stepper2.setMinPulseWidth(200);


  while (true) {
  	if (stepper1.distanceToGo() == 0)
		stepper1.moveTo(-stepper1.currentPosition());
	stepper1.run();
  	if (stepper2.distanceToGo() == 0)
		stepper2.moveTo(-stepper2.currentPosition());
	stepper2.run();
  }
}
