#include "alertConfigurationParameters.h"
#include "typewise-alert.h"

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

char AlertMessageForMail[3][100] =
{"Hi, the temperature is normal\n","Hi, the temperature is too low\n","Hi, the temperature is too high\n"};
