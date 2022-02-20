#pragma once

BreachType inferBreach(BatteryCharacter batteryCharacteristics, float tempValue);
BatteryCharacter populateOperatingTemperatureValues(CoolingType coolingType);
bool checkAndAlert(AlertTarget alertTarget, CoolingType coolingType, float tempValue);
void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
bool alertBreach(AlertTarget alertTarget, BreachType breachType);
bool validateEnumValue(int enumValue, int maxPossibleValue);
