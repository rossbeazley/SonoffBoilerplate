add_library(arduinostub arduinostub/Arduino.cpp)

target_include_directories(arduinostub PUBLIC arduinostub/)

add_executable(DebouncedGPIO_test ../src/DebouncedGPIO.h ../src/DebouncedGPIO.cpp DebouncedGPIO.t.cpp)
add_executable(InteruptButton_test ../src/InteruptGPIOButton.h ../src/InteruptGPIOButton.cpp InteruptGPIO.t.cpp)
add_executable(GPIORelay_test ../src/GPIORelay.h ../src/GPIORelay.cpp GPIORelay.t.cpp)
add_executable(SonoffApplicationCore_test ../src/SonoffApplicationCore.h ../src/SonoffApplicationCore.cpp SonoffApplicationCore.t.cpp)

target_link_libraries(GPIORelay_test PRIVATE arduinostub)
target_link_libraries(SonoffApplicationCore_test PRIVATE arduinostub)
target_link_libraries(InteruptButton_test PRIVATE arduinostub)
target_link_libraries(DebouncedGPIO_test PRIVATE arduinostub)

add_test(NAME GPIORelay_test COMMAND GPIORelay_test)
add_test(NAME SonoffApplicationCore_test COMMAND SonoffApplicationCore_test)
add_test(NAME InteruptButton_test COMMAND InteruptButton_test)
add_test(NAME DebouncedGPIO_test COMMAND DebouncedGPIO_test)
