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

#include "quantum.h"
#include "rgbled.h"
#include "debug.h"

#if MATREUS_RGBLED

rgbled_config rgb;

void rgbled_init()
{
    rgb.red.port = B6;
    rgb.red.mode = 2;
    rgb.red.channel = 1;
    pwmled_init(&rgb.red);
    pwmled_enable(&rgb.red);

    rgb.green.port = B7;
    rgb.green.mode = 2;
    rgb.green.channel = 2;
    pwmled_init(&rgb.green);
    pwmled_enable(&rgb.green);

    rgb.blue.port = B8;
    rgb.blue.mode = 2;
    rgb.blue.channel = 3;
    pwmled_init(&rgb.blue);
    pwmled_enable(&rgb.blue);
}

void rgbled_set(int red, int green, int blue)
{
    pwmled_level(&rgb.red, red);
    pwmled_level(&rgb.green, green);
    pwmled_level(&rgb.blue, blue);
}

#endif // MATREUS_RGBLED

