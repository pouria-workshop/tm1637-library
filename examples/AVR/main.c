/**
 * Copyright (c) 2017-2018, Łukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 * Copyright (c) 2022, Changed to CodevisonAVR version BY Pouria Amiri
 *
 * This is AVR "Running Digits" example using tm1637-library,
 * https://github.com/pouria-workshop/tm1637-library .
 *
 */

#include <mega2560.h>
#include "tm1637.h"
#include <stdint.h>
#include <delay.h>
#include <i2c.h>

// Declare your global variables here

void main(void)
{
	uint8_t n, k = 0;

	/* setup */
	TM1637_init(1/*enable*/, 5/*brightness*/);

	/* loop */
	while (1) {
		for (n = 0; n < TM1637_POSITION_MAX; ++n) {
			TM1637_display_digit(n, (k + n) % 0x10);
		}
		TM1637_display_colon(1);
		delay_ms(200);
		TM1637_display_colon(0);
		delay_ms(200);
		k++;
	}
}
