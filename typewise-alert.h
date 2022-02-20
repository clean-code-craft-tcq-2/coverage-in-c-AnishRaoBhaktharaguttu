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
  .lowerLimitOfTemp = 0,
  .upperLimitOfTemp = 35,
  },
  {
  .lowerLimitOfTemp = 0,
  .upperLimitOfTemp = 45,
  },
  {
  .lowerLimitOfTemp = 0,
  .upperLimitOfTemp = 40,
  }
};

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

char AlertMessageForMail[3][20] =
{" normal\n"," too low\n"," too high\n"};

BreachType inferBreach(BatteryCharacter batteryCharacteristics, float tempValue);
BatteryCharacter populateOperatingTemperatureValues(CoolingType coolingType);
void checkAndAlert(AlertTarget alertTarget, CoolingType coolingType, float tempValue);
void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
