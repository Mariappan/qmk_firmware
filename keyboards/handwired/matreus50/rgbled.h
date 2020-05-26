/*
Copyright 2020 Mariappan Ramasamy <mariappan@outlook.in>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#if MATREUS_RGBLED

#include <hal.h>
#include "pwmled.h"

typedef struct _rgbled_config {
    pwmled_config_t red;
    pwmled_config_t green;
    pwmled_config_t blue;
} rgbled_config;

void rgbled_init(void);

void rgbled_set(int red, int green, int blue);

#endif // MATREUS_RGBLED
