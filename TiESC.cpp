/*
  TiESC.h - Library for Firing ESC's.
  Created by Rohit R. Abbadi, August 2, 2017.
  In the private domain.
*/
#include "Arduino.h"
#include "TiESC.h"
#include "Servo.h"

#define MAX_SIGNAL 2000
#define MIN_THRESHOLD_SIGNAL 1400
#define MIN_SIGNAL 700

TiESC::TiESC(int m1, int m2, int m3, int m4){
	_m1 = m1;
	_m2 = m2;
	_m3 = m3;
	_m4 = m4;
	Servo _motor1;
	Servo _motor2;
	Servo _motor3;
	Servo _motor4;
}

void TiESC::fire(){

	_motor1.attach(_m1);
	_motor2.attach(_m2);
	_motor3.attach(_m3);
	_motor4.attach(_m4);
	//Writing maximum output;
	balance(100);
	delay(1000);
	balance(0);
	//Writing minimum output;
	write(MIN_SIGNAL, MIN_SIGNAL, MIN_SIGNAL, MIN_SIGNAL);
	delay(2000);
}

int TiESC::getSignal(int percent){
	return map(percent, 0, 100, MIN_THRESHOLD_SIGNAL, MAX_SIGNAL);
}

void TiESC::throttle(int p1, int p2, int p3, int p4){
	write(getSignal(p1), getSignal(p2), getSignal(p3), getSignal(p4));
}

void TiESC::balance(int percent){
	int signal = getSignal(percent);
	write(signal, signal, signal, signal);
}

void TiESC::write(int s1, int s2, int s3, int s4){
	_motor1.writeMicroseconds(s1);
	_motor2.writeMicroseconds(s2);
	_motor3.writeMicroseconds(s3);
	_motor4.writeMicroseconds(s4);
}