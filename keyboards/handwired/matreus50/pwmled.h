/*
Copyright 2013 Mathias Andersson <wraul@dbox.se>
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

#if MATREUS_PWMLED

#include <stdint.h>
#include <stdbool.h>

#ifndef PWMLED_LEVELS
#    define PWMLED_LEVELS 31
#elif PWMLED_LEVELS > 31
#    error "Maximum value of PWMLED_LEVELS is 31"
#endif

#ifndef PWMLED_ON_STATE
#    define PWMLED_ON_STATE 1
#endif

typedef struct {
    long unsigned int port; // MAARI: FIX this
    int mode;
    int channel;
    // PWMDriver pwmd;

    bool    enable : 1;
    bool    breathing : 1;
    uint8_t reserved : 1;  // Reserved for possible future pwmled modes
    uint8_t level : 5;
} pwmled_config_t;

void    pwmled_init(pwmled_config_t *config);
void    pwmled_enable(pwmled_config_t *config);
void    pwmled_disable(pwmled_config_t *config);
void    pwmled_level(pwmled_config_t *config, uint8_t level);
void    pwmled_set(pwmled_config_t *config, uint8_t level);
// void    pwmled_toggle(pwmled_config_t *config);
// bool    is_pwmled_enabled(pwmled_config_t *config);
// void    pwmled_step(pwmled_config_t *config);
// void    pwmled_increase(pwmled_config_t *config);
// void    pwmled_decrease(pwmled_config_t *config);
// uint8_t get_pwmled_level(pwmled_config_t *config);

#endif // MATREUS_PWMLED
