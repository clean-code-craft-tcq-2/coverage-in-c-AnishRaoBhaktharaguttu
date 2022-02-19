#include "typewise-alert.h"
#include <stdio.h>

const char* messageTemplate = "Hi, the temperature is\n";

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType classifyTemperatureBreach(
    CoolingType coolingType, double temperatureInC) {
  switch(coolingType) {
    case PASSIVE_COOLING:
      setOperatingLimitsForCoolingType(0,35);
      break;
    case HI_ACTIVE_COOLING:
      setOperatingLimitsForCoolingType(0,45);
      break;
    case MED_ACTIVE_COOLING:
    default:
      setOperatingLimitsForCoolingType(0,40);
      break;
  }
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

CoolingLimit setOperatingLimitsForCoolingType(float lowerLimit, float upperLimit){
    CoolingLimit coolingLimit;
    coolingLimit.lowerLimit = lowerLimit;
    coolingLimit.upperLimit = upperLimit;
    return coolingLimit;
}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);

  switch(alertTarget) {
    case TO_CONTROLLER:
      sendToController(breachType);
      break;
    case TO_EMAIL:
      sendToEmail(breachType);
      break;
  }
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void printStatusOnConsole(const char* statement) {
	printf("%s \n", statement);
}

void setWarningMessage(const char* status){
   	  char warnMsg[100];
      strcpy(warnMsg, messageTemplate);
  	  strcat(warnMsg,  status);
      printStatusOnConsole(warnMsg);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  switch(breachType) {
    case TOO_LOW:
      setWarningMessage("too low");
      break;
    case TOO_HIGH:
      setWarningMessage("too high");
      break;
    case NORMAL:
      setWarningMessage("normal");
      break;
  }
}
