#include "../unity/unity_fixture.h"
#include "../src/LedDriver.h"

static uint16_t virtualLeds;

TEST_GROUP(LedDriver);

TEST_GROUP_RUNNER(LedDriver)
{
	RUN_TEST_CASE(LedDriver, LedsOffAfterCreate);
	RUN_TEST_CASE(LedDriver, TurnOnLedOne);
	RUN_TEST_CASE(LedDriver, TurnOffLedOne);
	RUN_TEST_CASE(LedDriver, TurnOnMultipleLeds);
	RUN_TEST_CASE(LedDriver, TurnOffAnyLed);
	RUN_TEST_CASE(LedDriver, AllOn);
	
	RUN_TEST_CASE(LedDriver, LedMemoryIsNotReadable);

}

TEST_SETUP(LedDriver)
{
	LedDriver_Create(&virtualLeds);
}

TEST_TEAR_DOWN(LedDriver)
{
}


TEST(LedDriver, LedsOffAfterCreate)
{
	uint16_t virtualLeds = 0xffff;
	LedDriver_Create(&virtualLeds);
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

TEST(LedDriver, TurnOnLedOne)
{
	LedDriver_TurnOn(1);
	TEST_ASSERT_EQUAL_HEX16(1, virtualLeds);
}

TEST(LedDriver, TurnOffLedOne)
{
	LedDriver_TurnOn(1);
	LedDriver_TurnOff(1);
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

TEST(LedDriver, TurnOnMultipleLeds)
{
	LedDriver_TurnOn(9);
	LedDriver_TurnOn(8);
	TEST_ASSERT_EQUAL_HEX16(0x180, virtualLeds);
}


// ovo je test 5 a ne 6 kako sam mislio ranije :D
TEST(LedDriver, TurnOffAnyLed)
{
	LedDriver_TurnAllOn();
	LedDriver_TurnOff(8);
	TEST_ASSERT_EQUAL_HEX16(0xff7f, virtualLeds);
}

TEST(LedDriver, AllOn)
{
	LedDriver_TurnAllOn();
	TEST_ASSERT_EQUAL_HEX16(0xffff, virtualLeds);
}


// sta ako se LED state ne moze direktno vidjeti/procitati?!
// onda ovi testovi nece raditi kad ih spustimo na hardware...
// trebacemo malo refactoring raditi :D
IGNORE_TEST(LedDriver, LedMemoryIsNotReadable)
{
	virtualLeds = 0xffff; // ovde smo prepisali 0x0 poslije "setup-a"... kao emulacija nemogucnosti citanja stanja...
	LedDriver_TurnOn(8);
	TEST_ASSERT_EQUAL_HEX16(0x80, virtualLeds);
}

