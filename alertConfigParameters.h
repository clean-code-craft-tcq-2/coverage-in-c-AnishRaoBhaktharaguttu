
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

extern BatteryCharacter BatteryTemperatureValues[3];
extern char AlertMessageForMail[3][100];
