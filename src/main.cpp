/*
 * rcProto
 * main.cpp
 *
 * The main file for an Arduino interface between
 * a Raspberry Pi Model 3 and a suite of sensors
 * and actuators
 *
 * Coastal Oceanography and Autonomous Systems Laboratory
 * University of California, Santa Barbara
 */

#include <Arduino.h>

#include "info.h"
#include "RPiComm.h"
#include "IMUComm.h"
#include "GPSComm.h"
#include "CarComm.h"

// I2C pins: IMU
#define SDA 20
#define SCL 21

// PWM pins: ESC, Steering
#define ESC 2
#define STR 3

// Devices
RPiComm* pRPi;
GPSComm* pGPS;
IMUComm* pIMU;
CarComm* pCar;

// TODO: Check whether "struct" must be stated
struct Position pos;
struct Momentum mom;
struct Goals goals;

void setup() {
  Serial.begin(115200);

  // TODO: implement "RPiComm(HardwareSerial, int)"
  pRPi = new RPiComm(&Serial1, 115200);
  // TODO: implement "GPSComm(HardwareSerial, int)"
  pGPS = new GPSComm(&Serial2, 9600);
  // TODO: implement "IMUComm(int, int)"
  pIMU = new IMUComm(SDA, SCL);
  // TODO: implement "CarComm(int, int)"
  pCar = new CarComm(ESC, STR);
}

void loop() {
  // TODO: test "Position GPSComm::update()"
  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  // TODO: !!! Speed and Heading are from GPS !!! Refactor accordingly
  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  pos = pGPS->update();
  // TODO: implement "Momentum IMUComm::update()"
  ine = pIMU->update();

  // TODO: implement "void RPiComm::postAll(Position, Momentum)"
  pRPi->postAll(pos, mom);
  // TODO: implement "Goals RPiComm::updateGoals()"
  goals = RPi->updateGoals();

  // TODO: implement "void CarComm::command(Goals)"
  Car.command(goals);
}
