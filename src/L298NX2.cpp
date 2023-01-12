/*
  L298N.cpp - Libreria per gestire i movimenti di un motore DC con il modulo L298N
  Autore:   Andrea Lombardo
  Sito web: http://www.lombardoandrea.com  
*/

#include "L298NX2.h"
#include "L298N.h"

#define DEBUG 0

typedef void (*CallBackFunction)();

L298NX2::L298NX2(uint8_t pinEnable_A,
                 uint8_t pinIN1_A,
                 uint8_t pinIN2_A,
                 uint8_t pinEnable_B,
                 uint8_t pinIN1_B,
                 uint8_t pinIN2_B) : _motorA(pinEnable_A,
                                             pinIN1_A,
                                             pinIN2_A),
                                     _motorB(pinEnable_B,
                                             pinIN1_B,
                                             pinIN2_B)
{
  _canMove = true;
  _lastMs = 0;
}

L298NX2::L298NX2(uint8_t pinIN1_A,
                 uint8_t pinIN2_A,
                 uint8_t pinIN1_B,
                 uint8_t pinIN2_B) : _motorA(pinIN1_A,
                                             pinIN2_A),
                                     _motorB(
                                         pinIN1_B,
                                         pinIN2_B)
{
  _canMove = true;
  _lastMs = 0;
}

void trace(String msg)
{
  if (DEBUG)
  {
    Serial.println(msg);
  }
}

//Motor A
void L298NX2::setSpeedA(unsigned short pwmVal)
{
  _motorA.setSpeed(pwmVal);
}

unsigned short L298NX2::getSpeedA()
{
  return _motorA.isMoving() ? _motorA.getSpeed() : 0;
}

void L298NX2::forwardA()
{
  _motorA.forward();
}

void L298NX2::backwardA()
{
  _motorA.backward();
}

void L298NX2::runA(L298N::Direction direction)
{
  _motorA.run(direction);
}

void L298NX2::runForA(unsigned long delay_A, L298N::Direction direction_A)
{
  trace("runForA(d, d)");
  _motorA.runFor(delay_A, direction_A);
}

void L298NX2::runForA(unsigned long delay_A, L298N::Direction direction_A, CallBackFunction callback_A)
{
  trace("runForA(d, d, c)");
  _motorA.runFor(delay_A, direction_A, callback_A);
}

void L298NX2::forwardForA(unsigned long delay, CallBackFunction callback)
{
  this->runForA(delay, L298N::FORWARD, callback);
}

void L298NX2::forwardForA(unsigned long delay)
{
  this->runForA(delay, L298N::FORWARD);
}

void L298NX2::backwardForA(unsigned long delay, CallBackFunction callback)
{
  this->runForA(delay, L298N::BACKWARD, callback);
}

void L298NX2::backwardForA(unsigned long delay)
{
  this->runForA(delay, L298N::BACKWARD);
}

void L298NX2::stopA()
{
  _motorA.stop();
}

void L298NX2::resetA()
{
  _motorA.reset();
}

boolean L298NX2::isMovingA()
{
  return _motorA.isMoving();
}

L298N::Direction L298NX2::getDirectionA()
{
  return _motorA.getDirection();
}

//Motor B
void L298NX2::setSpeedB(unsigned short pwmVal)
{
  _motorB.setSpeed(pwmVal);
}

unsigned short L298NX2::getSpeedB()
{
  return _motorB.isMoving() ? _motorB.getSpeed() : 0;
}

void L298NX2::forwardB()
{
  _motorB.forward();
}
void L298NX2::backwardB()
{
  _motorB.backward();
}

void L298NX2::runB(L298N::Direction direction)
{
  _motorB.run(direction);
}

void L298NX2::runForB(unsigned long delay_B, L298N::Direction direction_B)
{
  _motorB.runFor(delay_B, direction_B);
}
void L298NX2::runForB(unsigned long delay_B, L298N::Direction direction_B, CallBackFunction callback_B)
{
  _motorB.runFor(delay_B, direction_B, callback_B);
}

void L298NX2::forwardForB(unsigned long delay, CallBackFunction callback)
{
  this->runForB(delay, L298N::FORWARD, callback);
}

void L298NX2::forwardForB(unsigned long delay)
{
  this->runForB(delay, L298N::FORWARD);
}

void L298NX2::backwardForB(unsigned long delay, CallBackFunction callback)
{
  this->runForB(delay, L298N::BACKWARD, callback);
}

void L298NX2::backwardForB(unsigned long delay)
{
  this->runForB(delay, L298N::BACKWARD);
}

void L298NX2::stopB()
{
  _motorB.stop();
}

void L298NX2::resetB()
{
  _motorB.reset();
}

boolean L298NX2::isMovingB()
{
  return _motorB.isMoving();
}

L298N::Direction L298NX2::getDirectionB()
{
  return _motorB.getDirection();
}

// Both
void L298NX2::setSpeed(unsigned short pwmVal)
{
  _motorA.setSpeed(pwmVal);
  _motorB.setSpeed(pwmVal);
}

void L298NX2::forward()
{
  _motorA.forward();
  _motorB.forward();
}

void L298NX2::backward()
{
  _motorA.backward();
  _motorB.backward();
}

void L298NX2::run(L298N::Direction direction)
{
  _motorA.run(direction);
  _motorB.run(direction);
}

//Timing and callback
void L298NX2::runFor(unsigned long delay, L298N::Direction direction, CallBackFunction callback)
{

  if ((_lastMs == 0) && _canMove)
  {
    _lastMs = millis();
    switch (direction)
    {
    case L298N::FORWARD:
      this->forward();
      break;
    case L298N::BACKWARD:
      this->backward();
      break;
    case L298N::STOP:
    default:
      this->stop();
      break;
    }
  }

  if (((millis() - _lastMs) > delay) && _canMove)
  {
    this->stop();
    _lastMs = 0;
    _canMove = false;

    callback();
  }
}

void L298NX2::runFor(unsigned long delay, L298N::Direction direction)
{
  this->runFor(delay, direction, fakeCallback);
}

void L298NX2::forwardFor(unsigned long delay, CallBackFunction callback)
{
  this->runFor(delay, L298N::FORWARD, callback);
}

void L298NX2::forwardFor(unsigned long delay)
{
  this->runFor(delay, L298N::FORWARD);
}

void L298NX2::backwardFor(unsigned long delay, CallBackFunction callback)
{
  this->runFor(delay, L298N::BACKWARD, callback);
}

void L298NX2::backwardFor(unsigned long delay)
{
  this->runFor(delay, L298N::BACKWARD);
}

void L298NX2::stop()
{
  _motorA.stop();
  _motorB.stop();
}

void L298NX2::reset()
{
  _canMove = true;
  _motorA.reset();
  _motorB.reset();
}

void L298NX2::fakeCallback()
{
}