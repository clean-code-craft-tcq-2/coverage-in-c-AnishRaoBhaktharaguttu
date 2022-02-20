#include "typewise-alert.h"
#include <stdio.h>
#include <string.h>

void printWarningMessageForEmail(const char* recipient, char alertStatus[]){
    printf("To: %s\n%s", recipient, alertStatus);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  printWarningMessageForEmail(recepient, AlertMessageForMail[breachType]);
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}
                    
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
                    
void checkAndAlert(AlertTarget alertTarget, CoolingType coolingType, float tempValue) {
  BatteryCharacter batteryCharacteristics = populateOperatingTemperatureValues(coolingType);
  BreachType breachType = inferBreach(batteryCharacteristics, tempValue);
  alertBreach(alertTarget, breachType);
}
