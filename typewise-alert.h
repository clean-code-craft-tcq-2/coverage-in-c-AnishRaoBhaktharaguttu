#pragma once

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

typedef struct {
  CoolingType coolingType;
  float lowerLimitOfTemp;
  float upperLimitOfTemp;
  char brand[48];
} BatteryCharacter;

BatteryCharacter BatteryTemperatureValues[3] =
{
  {
  lowerLimit = 0,
  upperLimit = 35,
  },
  {
  lowerLimit = 0,
  upperLimit = 45,
  },
  {
  .lowerLimit = 0,
  .upperLimit = 40,
  }
};

BreachType inferBreach(BatteryCharacter batteryCharacteristics, float tempValue);
BatteryCharacter populateOperatingTemperatureValues(CoolingType coolingType);

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

char AlertMessageForMail[3][20] =
{" normal\n"," too low\n"," too high\n"};

void checkAndAlert(
  AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
