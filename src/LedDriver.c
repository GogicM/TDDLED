#include "LedDriver.h"

enum {ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON};
enum {FIRST_LED = 1, LAST_LED = 16};

static uint16_t* ledsAddress;
static uint16_t ledsImage;


// HELPERS
static uint16_t convertLedNumberToBit(int ledNumber)
{
	return 1 << (ledNumber - 1);
}

static void updateHardware(void)
{
	*ledsAddress = ledsImage;
}

static uint8_t IsLedOutOfBounds(int ledNumber)
{
	return (ledNumber < FIRST_LED) || (ledNumber > LAST_LED);
}

static void setLedImageBit(int ledNumber)
{
	ledsImage |= convertLedNumberToBit(ledNumber);
}

static void clearLedImageBit(int ledNumber)
{
	ledsImage &= ~convertLedNumberToBit(ledNumber);
}


// DRIVER FUNCTIONS - EXPORTED!
void LedDriver_Create(uint16_t* address)
{
	ledsAddress = address;
	ledsImage = ALL_LEDS_OFF;
	updateHardware();
}

void LedDriver_Destroy(void)
{
}

void LedDriver_TurnOn(int ledNumber)
{
	if (IsLedOutOfBounds(ledNumber))
		return;
	
	setLedImageBit(ledNumber);
	updateHardware();
}

void LedDriver_TurnOff(int ledNumber)
{
	if (IsLedOutOfBounds(ledNumber))
		return;
	
	clearLedImageBit(ledNumber);
	updateHardware();
}


void LedDriver_TurnAllOn(void)
{
	ledsImage = ALL_LEDS_ON;
	updateHardware();
}

uint16_t LedDriver_IsOn(int ledNumber)
{
	if (IsLedOutOfBounds(ledNumber))
		return FALSE;

	return (ledsImage & (convertLedNumberToBit(ledNumber)));
}

// JE LI OVO FINO STO SMO VEC DODALI CODE UMJESTO DA PRVO IDE TEST?!
uint16_t LedDriver_IsOff(int ledNumber)
{
	return FALSE; //!LedDriver_IsOn(ledNumber);
}

