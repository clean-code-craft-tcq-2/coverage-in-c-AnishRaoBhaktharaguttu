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

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

BreachType inferBreach(BatteryCharacter batteryCharacteristics, float tempValue);
BatteryCharacter populateOperatingTemperatureValues(CoolingType coolingType);
void checkAndAlert(AlertTarget alertTarget, CoolingType coolingType, float tempValue);
void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
