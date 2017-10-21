add_library(arduinostub arduinostub/Arduino.cpp)

target_include_directories(arduinostub PUBLIC arduinostub/)

add_executable(GPIORelay_test ../GPIORelay.h ../GPIORelay.cpp GPIORelay.t.cpp)
add_executable(SonoffRelay_test ../SonoffRelay.cpp ../SonoffRelay.h SonoffRelay.t.cpp)
add_executable(SonoffApplicationCore_test ../SonoffApplicationCore.h ../SonoffApplicationCore.cpp SonoffApplicationCore.t.cpp)

target_link_libraries(GPIORelay_test PRIVATE arduinostub)
target_link_libraries(SonoffRelay_test PRIVATE arduinostub)
target_link_libraries(SonoffApplicationCore_test PRIVATE arduinostub)

add_test(NAME GPIORelay_test COMMAND GPIORelay_test)
add_test(NAME SonoffRelay_test COMMAND SonoffRelay_test)
add_test(NAME SonoffApplicationCore_test COMMAND SonoffApplicationCore_test)
