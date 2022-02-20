#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "alertConfigParameters.h"
#include "typewise-alert.h"

TEST_CASE("ValidateEnumValue - Passing enum value satisfying the range - Positive use case ") {
  bool validateStatus = validateEnumValue (2,3);
  REQUIRE(validateStatus  == true);
}

TEST_CASE("ValidateEnumValue - Passing enum value greater than the maximum accepted value - Negative use case ") {
  bool validateStatus = validateEnumValue (4,3);
  REQUIRE(validateStatus  == false);
}


TEST_CASE("ValidateEnumValue - Passing enum value lesser than zero - Negative use case ") {
  bool validateStatus = validateEnumValue (-4,3);
  REQUIRE(validateStatus  == false);
}

TEST_CASE("ValidateEnumValue - Passing enum value lesser than zero but greater than maximum accepted value - Negative use case  ") {
  bool validateStatus = validateEnumValue (-5,-7);
  REQUIRE(validateStatus  == false);
}

TEST_CASE("InferBreach -Temperature value is less than operating lower limit") {
  BatteryCharacter batteryCharacteristics;
  batteryCharacteristics.lowerLimitOfTemp  = 25;
  batteryCharacteristics.upperLimitOfTemp  = 60;
  float tempValue = 10;
  REQUIRE(inferBreach(batteryCharacteristics, tempValue) == TOO_LOW);
}

TEST_CASE("InferBreach - Temperature value is more than operating higher limit") {
  BatteryCharacter batteryCharacteristics;
  batteryCharacteristics.lowerLimitOfTemp  = 25;
  batteryCharacteristics.upperLimitOfTemp  = 60;
  float tempValue = 65;
  REQUIRE(inferBreach(batteryCharacteristics, tempValue) == TOO_HIGH);
}


TEST_CASE("InferBreach - Temperature value is in the normal operating range") {
  BatteryCharacter batteryCharacteristics;
  batteryCharacteristics.lowerLimitOfTemp  = 25;
  batteryCharacteristics.upperLimitOfTemp  = 60;
  float tempValue = 43;
  REQUIRE(inferBreach(batteryCharacteristics, tempValue) == NORMAL);
}

TEST_CASE("populateOperatingTemperatureValues - Populate the lower and upper temperature limits based on cooling type - PASSIVE_COOLING ") {
  BatteryCharacter batteryCharacteristics;
  batteryCharacteristics = populateOperatingTemperatureValues(PASSIVE_COOLING);
  REQUIRE(batteryCharacteristics.coolingType  == PASSIVE_COOLING);
  REQUIRE(batteryCharacteristics.lowerLimitOfTemp  == 0);
  REQUIRE(batteryCharacteristics.upperLimitOfTemp  == 35);
}

TEST_CASE("populateOperatingTemperatureValues - Populate the lower and upper temperature limits based on cooling type - HI_ACTIVE_COOLING ") {
  BatteryCharacter batteryCharacteristics;
  batteryCharacteristics = populateOperatingTemperatureValues(HI_ACTIVE_COOLING);
  REQUIRE(batteryCharacteristics.coolingType  == HI_ACTIVE_COOLING);
  REQUIRE(batteryCharacteristics.lowerLimitOfTemp  == 0);
  REQUIRE(batteryCharacteristics.upperLimitOfTemp  == 45);
}

TEST_CASE("populateOperatingTemperatureValues - Populate the lower and upper temperature limits based on cooling type - MED_ACTIVE_COOLING ") {
  BatteryCharacter batteryCharacteristics;
  batteryCharacteristics = populateOperatingTemperatureValues(MED_ACTIVE_COOLING);
  REQUIRE(batteryCharacteristics.coolingType  == MED_ACTIVE_COOLING);
  REQUIRE(batteryCharacteristics.lowerLimitOfTemp  == 0);
  REQUIRE(batteryCharacteristics.upperLimitOfTemp  == 40);
}

TEST_CASE("AlertBreach - Alert message to controller with breach level NORMAL ") {
  alertBreach(TO_CONTROLLER, NORMAL);  
}

TEST_CASE("AlertBreach - Alert message to email with breach level NORMAL ") {
  alertBreach(TO_EMAIL, NORMAL);
}

TEST_CASE("CheckAndAlert - TO_CONTROLLER , PASSIVE_COOLING with all range of temp values ") {
  checkAndAlert(TO_CONTROLLER,PASSIVE_COOLING,20);
  checkAndAlert(TO_CONTROLLER,PASSIVE_COOLING,38);
  checkAndAlert(TO_CONTROLLER,PASSIVE_COOLING,-5);
}

