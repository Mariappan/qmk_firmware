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
 * Pins A11, A12 cannot be used since it is used for USB device
 */

#define MATRIX_ROW_PINS { A0, A1, A3, A2 }
#define MATRIX_COL_PINS { B13, B14, B15, A8, A9, A10, B12, A4, A5, A6, A7, B1, B0 }

#define UNUSED_PINS

#define OLED_TIMEOUT            10000
#define OLED_SCROLL_TIMEOUT     3000

