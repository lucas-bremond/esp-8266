# ESP 8266

## Description

Template ESP 8266 project.

## Hardware

### Parts

#### Microcontroller

[WEMOS D1 mini](https://www.aliexpress.com/item/D1-mini-Mini-NodeMcu-4M-bytes-Lua-WIFI-Internet-of-Things-development-board-based-ESP8266/32529101036.html?spm=2114.13010608.0.0.HZtg9v)

## Firmware

### Setup

#### Configuration

Create a `./files/setting.json` configuration file with the following content:

```json
{
    "network":
    {
        "ssid": "WIFI_SSID",
        "password": "WIFI_PASSWORD"
    }

}
```

#### Build

```bash
make
```

#### Flash

```bash
make flash
```

## Copyright

(c) 2019 Lucas Brémond

Citing Peter Andersson, author of the great [SPIFFS](https://github.com/pellepl/spiffs) library:

*For legal stuff, see LICENSE.*
*Basically, you may do whatever you want with the source.*
*Use, modify, sell, print it out, roll it and smoke it - as long as I won't be held responsible.*
