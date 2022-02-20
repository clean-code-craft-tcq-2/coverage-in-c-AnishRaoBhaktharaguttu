#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "alertConfigParameters.h"
#include "typewise-alert.h"

TEST_CASE("InferBreach -Temperature value is less than operating lower limit") {
  BatteryCharacter batteryCharacteristics;
  batteryCharacteristics.lowerLimitOfTemp  = 20;
  batteryCharacteristics.upperLimitOfTemp  = 50;
  float tempValue = 10;
  REQUIRE(inferBreach(batteryCharacteristics, tempValue) == TOO_LOW);
}
