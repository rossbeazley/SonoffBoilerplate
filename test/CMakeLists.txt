add_library(arduinostub arduinostub/Arduino.cpp)

target_include_directories(arduinostub PUBLIC arduinostub/)

add_executable(MQTTOutbound_test ../src/mqtt/MQTTOutbound.h ../src/mqtt/MQTTOutbound.cpp MQTTOutbound.t.cpp)
add_executable(MQTTInbound_test ../src/mqtt/MQTTInbound.h ../src/mqtt/MQTTInbound.cpp MQTTInbound.t.cpp)
add_executable(DebouncedGPIO_test ../src/buttons/DebouncedGPIO.h ../src/buttons/DebouncedGPIO.cpp DebouncedGPIO.t.cpp)
add_executable(InteruptButton_test ../src/buttons/InteruptGPIOButton.h ../src/buttons/InteruptGPIOButton.cpp InteruptGPIO.t.cpp)
add_executable(GPIORelay_test ../src/GPIORelay.h ../src/GPIORelay.cpp GPIORelay.t.cpp)
add_executable(RelayLightSwitch_test ../src/RelayLightSwitch.h ../src/RelayLightSwitch.cpp RelayLightSwitch.t.cpp)

target_link_libraries(GPIORelay_test PRIVATE arduinostub)
target_link_libraries(RelayLightSwitch_test PRIVATE arduinostub)
target_link_libraries(InteruptButton_test PRIVATE arduinostub)
target_link_libraries(DebouncedGPIO_test PRIVATE arduinostub)
target_link_libraries(MQTTOutbound_test)
target_link_libraries(MQTTInbound_test)

add_test(NAME MQTTInbound_test COMMAND MQTTInbound_test)
add_test(NAME MQTTOutbound_test COMMAND MQTTOutbound_test)
add_test(NAME GPIORelay_test COMMAND GPIORelay_test)
add_test(NAME RelayLightSwitch_test COMMAND SonoffApplicationCore_test)
add_test(NAME InteruptButton_test COMMAND InteruptButton_test)
add_test(NAME DebouncedGPIO_test COMMAND DebouncedGPIO_test)
