add_library(arduinostub arduinostub/Arduino.cpp)

target_include_directories(arduinostub PUBLIC arduinostub/)

add_executable(SonoffRelay_test ../SonoffRelay.cpp ../SonoffRelay.h SonoffRelay.t.cpp ../SonoffApplicationCore.h ../SonoffApplicationCore.cpp SonoffApplicationCore.t.cpp)

target_link_libraries(SonoffRelay_test PRIVATE arduinostub)

add_test(NAME SonoffRelay_test COMMAND SonoffRelay_test)
