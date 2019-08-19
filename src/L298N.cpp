/*
  L298N.cpp - Libreria per gestire i movimenti di un motore DC con il modulo L298N
  Autore:   Andrea Lombardo
  Sito web: http://www.lombardoandrea.com  
*/

#include "L298N.h"

typedef void (*CallBackFunction) ();

//pinIN1 and pinIN2 should be pwm pins and enable pin in L298N should be connected to HIGH
L298N::L298N(uint8_t pinIN1, uint8_t pinIN2){
  _withoutEnablemode = true;
  _pinIN1 = pinIN1;
  _pinIN2 = pinIN2;
  _pwmVal = 100;
  _isMoving = false;
  _canMove = true;
  _lastMs = 0;
}

L298N::L298N(uint8_t pinEnable, uint8_t pinIN1, uint8_t pinIN2){
  _withoutEnablemode = false;
  _pinEnable = pinEnable;
  _pinIN1 = pinIN1;
  _pinIN2 = pinIN2;
  _pwmVal = 100;
  _isMoving = false;
  _canMove = true;
  _lastMs = 0;

  pinMode(_pinEnable, OUTPUT);
  pinMode(_pinIN1, OUTPUT);
  pinMode(_pinIN2, OUTPUT);
}


void L298N::setSpeed(unsigned short pwmVal){
  if (pwmVal>255) pwmVal = 255;    //limit pwm value to 255
  _pwmVal = pwmVal;
}

unsigned short L298N::getSpeed(){
  return _pwmVal;
}

void L298N::forward(){
  if (!_withoutEnablemode){
    digitalWrite(_pinIN1, HIGH);
    digitalWrite(_pinIN2, LOW);
    
    analogWrite(_pinEnable, _pwmVal);
  }
  else{
    analogWrite(_pinIN1, _pwmVal);
    analogWrite(_pinIN2, 0);
  }
  _isMoving = true;
}


void L298N::forwardFor(unsigned long delay, CallBackFunction callback){
  if ((_lastMs == 0) && _canMove) {
    _lastMs = millis();
    this->forward();
  }

  if (((millis() - _lastMs) > delay) && _canMove) {
    this->stop();
    _lastMs = 0;
    _canMove = false;

    callback();

  }
}

void L298N::forwardFor(unsigned long delay){
  this->forwardFor(delay, fakeCallback);
}


void L298N::backward(){
  if (!_withoutEnablemode){
    digitalWrite(_pinIN1, LOW);
    digitalWrite(_pinIN2, HIGH);

    analogWrite(_pinEnable, _pwmVal);
  }
  else{
    analogWrite(_pinIN1, 0);
    analogWrite(_pinIN2, _pwmVal);
  }

  _isMoving = true;
}

void L298N::backwardFor(unsigned long delay, CallBackFunction callback){

  if ((_lastMs == 0) && _canMove) {
    _lastMs = millis();
    this->backward();
  }

  if (((millis() - _lastMs) > delay) && _canMove) {
    this->stop();
    _lastMs = 0;
    _canMove = false;

    callback();

  }
}

void L298N::backwardFor(unsigned long delay){
  this->backwardFor(delay, fakeCallback);
}

void L298N::run(uint8_t direction){
  switch(direction){
    case BACKWARD:
      this->backward();
    break;
    case FORWARD:
      this->forward();
    break;
  }
}

void L298N::stop(){
  if (!_withoutEnablemode){
    digitalWrite(_pinIN1, LOW);
    digitalWrite(_pinIN2, LOW);

    analogWrite(_pinEnable, 255);
  }
  else{
    analogWrite(_pinIN1, 0);
    analogWrite(_pinIN2, 0);
  }

  _isMoving = false;
}

void L298N::reset(){
  _canMove = true;
}

boolean L298N::isMoving(){
  return _isMoving;
}

void L298N::fakeCallback(){

}