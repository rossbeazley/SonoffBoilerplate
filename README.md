# SonoffBoilerplate

This is a replacement firmware (Arduino IDE with ESP8266 core needed) for the ESP8266 based Sonoff devices. Use it as a starting block for customizing your Sonoff.

This started as a fork of [tzapu](https://github.com/tzapu) SonoffBoilerplate project, currently deleted from GitHub. But is now so different it mearly shares its name and a bit of code for the button on the top of the sonoff.

I am mostly using this project as a way of refreshing my C++ skills that have been rotting since 1999. At the same time I am challenging myself to understand how I can leverage a hexagonal architecture and accomplish on device tests of my technology adapters.

Here is some info on flashing your [sonoff](https://randomnerdtutorials.com/how-to-flash-a-custom-firmware-to-sonoff/).

and here is info on the microcontroller at the heart of your sonoff - [esp8266 core](https://github.com/esp8266/Arduino).

It has everything included in a nice plastic package. See more here at the [Sonoff manufacturer website](https://www.itead.cc/sonoff-wifi-wireless-switch.html).

## Getting started
First of all you will need to solder a 4 or 5 pin header on your Sonoff so you can flash the new firmware.

### Running Tests
To run the [unit tests](test/), open a terminal and navigate to the root project directory and execute the following:

```bash
$ test.sh
```

Im using a stand alone cmake based test sollution at the moment. I plan on integrating fully into the IDE since switching to platform.io

These are the next things up on my task list:

MQTT inbound channel, backport tests
 - then add ability to respond to broadcast
 - and operate on specific client ID (this is the bit that needs tests)


EEPROM settings
 - backport tests and slit the load/save out of the class

SonoffWifi
 - need to decouple from the settings
 - use setters on settings instead of passing in a settings object
 - maybe need a virtual class for the eeprom settings

