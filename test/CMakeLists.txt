# core arduino stub
add_library(arduinostub arduinostub/Arduino.cpp)

# arduino string stub support
add_library(SString arduinostub/SString.cpp)

# VS real arduino String support but compiled native
#add_library(pgmspace arduinostub/pgmspace.cpp)
#add_library(SString arduinostub/WString.cpp)
#add_library(stdlib_noniso arduinostub/stdlib_noniso.h)
#SET_TARGET_PROPERTIES(stdlib_noniso PROPERTIES LINKER_LANGUAGE C++)



target_include_directories(arduinostub PUBLIC arduinostub/)

add_executable(MQTTOutbound_test ../src/mqtt/MQTTOutbound.h ../src/mqtt/MQTTOutbound.cpp ../src/mqtt/MQTTConnection.h ../src/RelayLightSwitch.h MQTTOutbound.t.cpp)

add_executable(MQTTInbound_test ../src/mqtt/MQTTInbound.h ../src/mqtt/MQTTInbound.cpp ../src/mqtt/MQTTInboundCommand.h ../src/mqtt/MQTTInboundCommand.cpp MQTTInbound.t.cpp)
add_executable(DebouncedGPIO_test ../src/buttons/DebouncedGPIO.h ../src/buttons/DebouncedGPIO.cpp DebouncedGPIO.t.cpp)
add_executable(InteruptButton_test ../src/buttons/InteruptGPIOButton.h ../src/buttons/InteruptGPIOButton.cpp InteruptGPIO.t.cpp)
add_executable(GPIORelay_test ../src/GPIORelay.h ../src/GPIORelay.cpp GPIORelay.t.cpp)
add_executable(RelayLightSwitch_test ../src/RelayLightSwitch.h ../src/RelayLightSwitch.cpp RelayLightSwitch.t.cpp)


target_link_libraries(MQTTInbound_test PRIVATE arduinostub SString)


target_link_libraries(MQTTOutbound_test PRIVATE arduinostub SString)
target_link_libraries(GPIORelay_test PRIVATE arduinostub)
target_link_libraries(RelayLightSwitch_test PRIVATE arduinostub)
target_link_libraries(InteruptButton_test PRIVATE arduinostub)
target_link_libraries(DebouncedGPIO_test PRIVATE arduinostub)


add_test(NAME MQTTInbound_test COMMAND MQTTInbound_test)
add_test(NAME RelayLightSwitch_test COMMAND SonoffApplicationCore_test)
add_test(NAME InteruptButton_test COMMAND InteruptButton_test)
add_test(NAME GPIORelay_test COMMAND GPIORelay_test)
add_test(NAME DebouncedGPIO_test COMMAND DebouncedGPIO_test)

add_test(NAME MQTTOutbound_test COMMAND MQTTOutbound_test) 