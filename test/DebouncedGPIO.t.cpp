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

TEST_CASE("Debouncing high low from a gpio", "[DebouncedGPIO]" ) {

	CapturingLightSwitch cls{};	
	AbstractButton * debounced = new DebouncedGPIO{cls};
	debounced->low(0);


	SECTION("Low to High results in TOGGLE") {

		debounced->high(1);
		REQUIRE( cls.state == 0);
		debounced->loop(200);
		REQUIRE( cls.state == 4);
	}

	SECTION("Low to High quickly (less than 100 millis) results in no change") {

		int preState = cls.state;
		debounced->high(1);
		REQUIRE( cls.state == preState);
		debounced->loop(90);
		REQUIRE( cls.state == preState);
	}


}
