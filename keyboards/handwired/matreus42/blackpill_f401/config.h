/* Copyright 2019
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

#include "config_common.h"


/*
 * NOTE:
 * Pins A9, A11, A12 cannot be used since it is used for USB device
 */

#define MATRIX_ROW_PINS { A5, A6, A7, B0 }
#define MATRIX_COL_PINS { A10, A8, B15, B14, B13, B12, A4, A3, A2, A1, A0 }

#define UNUSED_PINS

#define MATREUS_LED

// #define BACKLIGHT_PIN           A0
// #define BACKLIGHT_PWM_DRIVER    PWMD2
// #define BACKLIGHT_PWM_CHANNEL   1

