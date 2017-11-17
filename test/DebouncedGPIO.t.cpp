#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../DebouncedGPIO.h"
class CapturingLightSwitch : public LightSwitch
{ 
	public:
		int state = 0;
		CapturingLightSwitch() { };
		void externalOn()
		{
			state=1;
		};
		void externalOff()
		{
			state=2;
		};
		void externalToggle()
		{
			state=4;
		};

};

TEST_CASE("Cold to high from a gpio", "[DebouncedGPIO]" ) {

	CapturingLightSwitch cls{};	
	AbstractButton * debounced = new DebouncedGPIO{cls};


	SECTION("Cold to High results in TOGGLE") {

		debounced->high(1);
		REQUIRE( cls.state == 0);
		debounced->loop(200);
		REQUIRE( cls.state == 4);
	}

	SECTION("Cold to High quickly (less than 100 millis) results in no change") {

		int preState = cls.state;
		debounced->high(1);
		REQUIRE( cls.state == preState);
		debounced->loop(90);
		REQUIRE( cls.state == preState);
	}

}


TEST_CASE("Cold to low from a gpio", "[DebouncedGPIO]" ) {

	CapturingLightSwitch cls{};	
	AbstractButton * debounced = new DebouncedGPIO{cls};


	SECTION("Cold to Low results in TOGGLE") {

		debounced->low(1);
		REQUIRE( cls.state == 0);
		debounced->loop(200);
		REQUIRE( cls.state == 4);
	}

	SECTION("Cold to Low quickly (less than 100 millis) results in no change") {

		int preState = cls.state;
		debounced->low(1);
		REQUIRE( cls.state == preState);
		debounced->loop(90);
		REQUIRE( cls.state == preState);
	}

}

TEST_CASE("High to Low","[DebouncedGPIO]") {
	CapturingLightSwitch cls{};
	AbstractButton * debounced = new DebouncedGPIO{cls};
	debounced->high(0);
	debounced->loop(101);
	cls.state = 1;

	SECTION("High to Low results in toggle") {
		debounced->low(1);
		debounced->loop(200);
		REQUIRE( cls.state == 4);
	}
}

TEST_CASE("Debounced high to Low","[DebouncedGPIO]") {
	CapturingLightSwitch cls{};
	AbstractButton * debounced = new DebouncedGPIO{cls};
	debounced->high(0);
	debounced->loop(101);
	cls.state = 1;

	SECTION("High to Low results in toggle") {
		debounced->low(1);
		debounced->low(2);
		debounced->high(3);
		debounced->low(3);
		debounced->low(3);
		debounced->loop(200);
		REQUIRE( cls.state == 4);
	}
}


TEST_CASE("Debounced Low to High","[DebouncedGPIO]") {
	CapturingLightSwitch cls{};
	AbstractButton * debounced = new DebouncedGPIO{cls};
	debounced->low(0);
	debounced->loop(101);
	cls.state = 2;

	SECTION("High to Low results in toggle") {
		debounced->high(1);
		debounced->low(2);
		debounced->high(3);
		debounced->high(3);
		debounced->high(3);
		debounced->loop(200);
		REQUIRE( cls.state == 4);
	}
}

TEST_CASE("Two presses Low to High, High to Low","[DebouncedGPIO]") {
	CapturingLightSwitch cls{};
	AbstractButton * debounced = new DebouncedGPIO{cls};
	debounced->low(0);
	debounced->loop(101);
	cls.state = 2;

	SECTION("High to Low results in toggle") {
		debounced->high(1);
		debounced->high(3);
		debounced->loop(200);
		cls.state = 1;

		debounced->low(201);
		debounced->low(203);
		debounced->loop(310);
		REQUIRE( cls.state == 4);
	}
}

