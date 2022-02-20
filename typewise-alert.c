#include "typewise-alert.h"
#include <stdio.h>

const char* messageTemplate = "Hi, the temperature is\n";

//Function to infer the nature of breach occured
BreachType inferBreach(BatteryCharacter batteryCharacteristics, float tempValue) 
{
  if(tempValue < batteryCharacteristics.lowerLimitOfTemp)
  {return TOO_LOW;
  }
  else if(tempValue > batteryCharacteristics.upperLimitOfTemp)
  { return TOO_HIGH;
  }
  return NORMAL;
}

BatteryCharacter populateOperatingTemperatureValues(CoolingType coolingType)
{
  BatteryCharacter batteryCharacteristics; 
  batteryCharacteristics.coolingType = coolingType;
  batteryCharacteristics.lowerLimitOfTemp = BatteryTemperatureValues[coolingType].lowerLimitOfTemp;
  batteryCharacteristics.upperLimitOfTemp = BatteryTemperatureValues[coolingType].upperLimitOfTemp;
  return batteryCharacteristics;
}

void checkAndAlert(AlertTarget alertTarget, CoolingType coolingType, float tempValue) {
  BatteryCharacter batteryCharacteristics;
  batteryCharacteristics = populateOperatingTemperatureValues(coolingType);
  BreachType breachType = inferBreach(batteryCharacteristics, tempValue);
  alertBreach(alertTarget, breachType);
}

void alertBreach(AlertTarget alertTarget, BreachType breachType){
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

void printWarningMessageForEmail(const char* recipient, char[] alertStatus){
    char warnMsg[100];
    strcpy(warnMsg, messageTemplate);
    strcat(warnMsg,  status);
    printf("To: %s\n%s", recipient, warnMsg);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  setWarningMessage(AlertMessageForMail[BreachTypeInfo]
}
