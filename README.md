# SonoffBoilerplate

This is a replacement firmware for the ESP8266 based Sonoff devices. Use it as a starting block for customizing your Sonoff.

## What's a "Sonoff"?
Sonoff is just a small ESP8266 based module, that can toggle mains power on it's output. It has everything included in a nice plastic package.
See more here [Sonoff manufacturer website](https://www.itead.cc/sonoff-wifi-wireless-switch.html)

## What can your code do for me?
The goal of this is to give you a kickstart. Using it as a starter package you should be fairly advanced on the way of making your Sonoff behave the way you want. Adding, removing features should now be trivial.

Features include (~~strikethrough~~ = not implemented yet)
- wifi credentials configuration/onboarding using [WiFiManager](https://github.com/tzapu/WiFiManager)
- web configuration portal to setup tokes, servers, ports, etc
- Blynk integration
- ~~MQTT integration~~
- ~~HTTP sever API~~
- OTA over the air firmware update
- turn off and on relay from onboard button ~~and external button~~

If you want a more complete/complex firmware you should check out the [Sonoff-MQTT-OTA-Arduino](https://github.com/arendst/Sonoff-MQTT-OTA-Arduino) project.

## Getting started
First of all you will need to solder a 4 or 5 pin header on your Sonoff so you can flash the new firmware.
