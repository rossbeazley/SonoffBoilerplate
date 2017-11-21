#include "LightSwitch.h"
#include "unity.h"

#ifdef UNIT_TEST

class FakeLogger : public Logger
{
    public:
        FakeLogger(){};
        void d(char* msg)
        {

        };
};

FakeLogger fakeLogger{};

//LightSwitch lightSwitch{&fakeLogger};

// void setUp(void) {
// // set stuff up here
// }

// void tearDown(void) {
// // clean stuff up here
// }

void test_universe(void) {
    TEST_ASSERT_EQUAL(32, 30+2);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_universe);
    UNITY_END();

    return 0;
}

#endif