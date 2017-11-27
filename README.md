# SonoffBoilerplate

https://github.com/esp8266/Arduino

This is a replacement firmware (Arduino IDE with ESP8266 core needed) for the ESP8266 based Sonoff devices. Use it as a starting block for customizing your Sonoff.

https://randomnerdtutorials.com/how-to-flash-a-custom-firmware-to-sonoff/

## What's a "Sonoff"?
Sonoff is just a small ESP8266 based module, that can toggle mains power on it's output. It has everything included in a nice plastic package.
See more here [Sonoff manufacturer website](https://www.itead.cc/sonoff-wifi-wireless-switch.html)

## Getting started
First of all you will need to solder a 4 or 5 pin header on your Sonoff so you can flash the new firmware.

### Running Tests
To run the [unit tests](test/), open a terminal and navigate to the root project directory and execute the following:

```bash
$ test.sh
```


Plan for delivery:
use existing
Wifi Managera
MQT
SONOFF button
implement
External Button
Relay and GPIORelayImpl
ApplicationCore


Next up, split the mqtt stuff into
A) a client that maintains connection
B) an outbound channel that posts to this client
C) an inbound channel that receives topic payloads



