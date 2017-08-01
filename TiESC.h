/*
  TiESC.h - Library for Firing ESC's.
  Created by Rohit R. Abbadi, August 2, 2017.
  In the private domain.
*/
#ifndef TiESC_h
#define TiESC_h

#include "Arduino.h"
#include "Servo.h"

class TiESC{
	public:
	    TiESC(int m1, int m2, int m3, int m4);
	    void fire();
	    void balance(int percent);
      void throttle(int p1, int p2, int p3, int p4);

    private:
    	int _m1;
    	int _m2;
    	int _m3;
    	int _m4;
    	Servo _motor1;
		  Servo _motor2;
		  Servo _motor3;
		  Servo _motor4;
      int getSignal(int percent);
      void write(int s1, int s2, int s3, int s4);
};

#endif