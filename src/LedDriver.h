#include <stdint.h>

#define FALSE 0
#define TRUE 1

void LedDriver_Create(uint16_t * address);
void LedDriver_Destroy(void);
void LedDriver_TurnOn(int ledNumber);
void LedDriver_TurnOff(int ledNumber);
void LedDriver_TurnAllOn(void);
uint16_t LedDriver_IsOn(int ledNumber);

