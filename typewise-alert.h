#pragma once

BreachType inferBreach(BatteryCharacter batteryCharacteristics, float tempValue);
BatteryCharacter populateOperatingTemperatureValues(CoolingType coolingType);
void checkAndAlert(AlertTarget alertTarget, CoolingType coolingType, float tempValue);
void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
void alertBreach(AlertTarget alertTarget, BreachType breachType);
