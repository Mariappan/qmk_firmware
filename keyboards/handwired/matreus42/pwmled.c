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

#if MATREUS_PWMLED

#include "quantum.h"
#include "pwmled.h"
#include <hal.h>
#include "debug.h"

// GENERIC
#    ifndef PWMLED_PWM_DRIVER
#        define PWMLED_PWM_DRIVER PWMD3
#    endif
#    ifndef PWMLED_PWM_CHANNEL
#        define PWMLED_PWM_CHANNEL 1
#    endif


bool is_pwmled_enabled(pwmled_config_t *config)
{
    return config->enable;
}

uint8_t get_pwmled_level(pwmled_config_t *config)
{
    return config->level;
}

static PWMConfig pwmCFG = {0xFFFF, /* PWM clock frequency  */
                           256,    /* PWM period (in ticks) 1S (1/10kHz=0.1mS 0.1ms*10000 ticks=1S) */
                           NULL,   /* No Callback */
                           {       /* Default all channels to disabled*/
                            {PWM_OUTPUT_DISABLED, NULL},
                            {PWM_OUTPUT_DISABLED, NULL},
                            {PWM_OUTPUT_DISABLED, NULL},
                            {PWM_OUTPUT_DISABLED, NULL}
                           },
                           0, /* HW dependent part.*/
                           0};

void pwmled_init(pwmled_config_t *config) {
#    ifdef USE_GPIOV1
    palSetPadMode(PAL_PORT(config->port), PAL_PAD(config->port),
                  PAL_MODE_STM32_ALTERNATE_PUSHPULL);
#    else
    palSetPadMode(PAL_PORT(config->port), PAL_PAD(config->port),
                  PAL_MODE_ALTERNATE(config->mode));
#    endif

    pwmCFG.channels[config->channel - 1].mode = PWM_OUTPUT_ACTIVE_HIGH;
    pwmStart(&PWMLED_PWM_DRIVER, &pwmCFG);

    pwmled_set(config, get_pwmled_level(config));
}

void pwmled_enable(pwmled_config_t *config) {
    if (config->enable) return;

    config->enable = true;
    if (config->level == 0)  // enabled but level == 0
        config->level = 1;
    dprintf("pwmled enable\n");
    pwmled_set(config, config->level);
}

void pwmled_disable(pwmled_config_t *config) {
    if (!config->enable) return;

    config->enable = false;
    dprintf("pwmled disable\n");
    pwmled_set(config, 0);
}

#if 0
void pwmled_increase(void) {
    if (config->level < PWMLED_LEVELS) {
        config->level++;
    }
    config->enable = 1;
    dprintf("pwmled increase: %u\n", config->level);
    pwmled_set(config, config->level);
}

void pwmled_decrease(void) {
    if (config->level > 0) {
        config->level--;
        config->enable = !!config->level;
    }
    dprintf("pwmled decrease: %u\n", config->level);
    pwmled_set(config, config->level);
}

void pwmled_toggle(void) {
    bool enabled = config->enable;
    dprintf("pwmled toggle: %u\n", enabled);
    if (enabled)
        pwmled_disable();
    else
        pwmled_enable();
}

void pwmled_step(void) {
    config->level++;
    if (config->level > PWMLED_LEVELS) {
        config->level = 0;
    }
    config->enable = !!config->level;
    dprintf("pwmled step: %u\n", config->level);
    pwmled_set(config, config->level);
}
#endif

void pwmled_level(pwmled_config_t *config, uint8_t level) {
    if (level > PWMLED_LEVELS) level = PWMLED_LEVELS;
    config->level  = level;
    config->enable = !!config->level;
    pwmled_set(config, config->level);
}

static uint16_t cie_lightness(uint16_t v) {
    if (v <= 5243)     // if below 8% of max
        return v / 9;  // same as dividing by 900%
    else {
        // add 16% of max and compare
        uint32_t y = (((uint32_t)v + 10486) << 8) / (10486 + 0xFFFFUL);
        // to get a useful result with integer division, we shift left in the
        // expression above and revert what we've done again after squaring.
        y = y * y * y >> 8;
        if (y > 0xFFFFUL)  // prevent overflow
            return 0xFFFFU;
        else
            return (uint16_t)y;
    }
}

void pwmled_set(pwmled_config_t *config, uint8_t level) {
    if (level == 0) {
        pwmDisableChannel(&PWMLED_PWM_DRIVER, config->channel - 1);
    } else {
        uint32_t duty = (uint32_t)(cie_lightness(0xFFFF * (uint32_t)level / PWMLED_LEVELS));
        pwmEnableChannel(&PWMLED_PWM_DRIVER, config->channel - 1,
                         PWM_FRACTION_TO_WIDTH(&PWMLED_PWM_DRIVER, 0xFFFF, duty));
    }
}

#endif // MATREUS_PWMLED
