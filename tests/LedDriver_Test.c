#include "../unity/unity_fixture.h"

TEST_GROUP(LedDriver);

TEST_SETUP(LedDriver)
{
}

TEST_TEAR_DOWN(LedDriver)
{
}

TEST_GROUP_RUNNER(LedDriver)
{
	RUN_TEST_CASE(LedDriver, LedsOffAfterCreate);
}

TEST(LedDriver, LedsOffAfterCreate)
{
	TEST_FAIL_MESSAGE("Start here");
}


