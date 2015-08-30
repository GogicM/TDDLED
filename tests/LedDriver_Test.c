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

