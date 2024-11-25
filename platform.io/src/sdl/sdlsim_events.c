/*
 * Rad Pro
 * Simulator events
 *
 * (C) 2022-2024 Gissio
 *
 * License: MIT
 */

#if defined(SIMULATOR)

#include <SDL.h>

#include "../events.h"

extern volatile uint32_t eventsCurrentTick;

float timerCountToSeconds = (1.0F / PULSE_MEASUREMENT_FREQUENCY);

void initEventsController(void)
{
}

void sleep(uint32_t value)
{
}

#endif
