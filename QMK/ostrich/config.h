// Copyright 2022 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"


// MATRIX CONFIGURATION -------------------------------------------------------
#include "_pin_defs_picoMCP.h"  // Named constants for MCP23017 pins

// Key matrix size
#define MATRIX_ROWS 4
#define MATRIX_COLS 10

// Direct matrix pins on the microcontroller
#define MATRIX_PINS \
    {  GP2,  GP3,  GP4,  GP5,  GP6,    GP28, GP27, GP26, GP22, GP21, \
       GP7,  GP8,  GP9, GP10, GP11,    GP20, GP19, GP18, M_A0, M_A1, \
      M_B7, M_B6, M_B5, M_B4, M_B3,    M_A2, M_A3, M_A4, M_A5, M_A6, \
                        M_B2, M_B1,    M_B0, M_A7                    }

// https://ww1.microchip.com/downloads/en/devicedoc/20001952c.pdf#page=15  FIGURE 3-6
// State of hardware address pins (A2, A1, A0).  0 if tied to GND, 1 if tied to VDD.
#define MCP23017_HW_ADDR_PINS  0b000

// ----------------------------------------------------------------------------

#define ENCODERS_PAD_A { GP12 }
#define ENCODERS_PAD_B { GP13 }

#ifdef OLED_ENABLE
#   define OLED_DISPLAY_128X32
#   define I2C1_SCL_PIN        GP0
#   define I2C1_SDA_PIN        GP1
#   define I2C_DRIVER I2CD1
#endif