# Rain & Snow

![Rain and snow animation running on the T-Display](media/demo.gif)

**Module 1: Generative Art** · Creative Embedded Systems (COMS BC3930), Fall 2026

A generative weather scene for the LilyGO T-Display (ESP32), inspired by the word transition, and specifically by the way weather changes. Every 10 seconds, the sky shifts between a rainy day and a snowy one. Every raindrop and snowflake is randomly determined by code, creating a unique scene every time.

## How it works

Everything is drawn on an invisible canvas (a sprite) first, then pushed to the screen all at once to prevent flicker. The scene is made of 50 drops, each stored as  an x and y position. Every frame, each drop moves down a little: rain falls fast as short lines, while snow falls slowly as small circles that drift left or right by a random amount. When a drop falls off the bottom, it's moved to a random spot at the top, so the pattern never repeats. Meanwhile, millis() (the time since the board turned on) controls which weather is showing, switching between rain and snow every 10 seconds.
 
## Hardware

- LilyGO TTGO T-Display (ESP32 with a 240×135 screen)
- USB-C cable

## Run it yourself

1. Install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Add ESP32 support: **Tools → Board → Boards Manager**, search `esp32`, and install.
3. Install the **TFT_eSPI** library from **Tools → Manage Libraries**.
4. Open `Documents/Arduino/libraries/TFT_eSPI/User_Setup_Select.h`, comment out
   the default setup line, and uncomment:
   `#include <User_Setups/Setup25_TTGO_T_Display.h>`
5. Open `weather_esp32/weather_esp32.ino`, select **ESP32 Dev Module** as the
   board, and click **Upload**.

## Change it Up - Have Fun!

Customize by changing these values:
| `+ 4` in the rain section for faster or slower rain | `+ 1` in the snow section for faster or slower snow | `10000` for how often the weather switches (milliseconds) | `50` (in all  places) for more or fewer rain/snow drops | `TFT_NAVY` / `TFT_LIGHTGREY` for different sky colors |

## Files
esp32-weather/
├── README.md
├── weather_esp32/
│   └── weather_esp32.ino
└── media/
    └── demo.gif
