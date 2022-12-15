/* Copyright 2022 hakbraley <hakbraley@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"
#define ___ KC_NO

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys, with the pin they are connected to.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents where those pins are in the switch matrix.
 * 
 * d[num] represents a direct pin               d02 = GP2
 * m[port][pin] represents a pin on MPC23017    mA7 = MPC pin A7
 */
#define LAYOUT_split_3x5_2( \
    d02, d03, d04, d05, d06,    d28, d27, d26, d22, d21, \
    d07, d08, d09, d10, d11,    d20, d19, d18, mA0, mA1, \
    mB7, mB6, mB5, mB4, mB3,    mA2, mA3, mA4, mA5, mA6, \
                   mB2, mB1,    mB0, mA7                 \
) \
{ \
    { d02, d03, d04, d05, d06, d28, d27, d26, d22, d21 }, \
    { d07, d08, d09, d10, d11, d20, d19, d18, mA0, mA1 }, \
    { mB7, mB6, mB5, mB4, mB3, mA2, mA3, mA4, mA5, mA6 }, \
    { mB2, mB1, mB0, mA7, ___, ___, ___, ___, ___, ___ }, \
}
