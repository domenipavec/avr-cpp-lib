/* File: pwm.cpp
 * PWM contains a pwm_worker class for easy software pwm.
 */
/* Copyright (c) 2012-2013 Domen Ipavec (domen.ipavec@z-v.si)
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "pwm.h"
#include "bitop.h"

avr_cpp_lib::pwm_worker::pwm_worker(pwm_channel * d) 
	:data(d) {
	
	// set all pins to output
	for (pwm_channel * x = data; x->channel != PWM_CHANNEL_END_VALUE; x++) {
		SETBIT(*(x->ddr), x->channel);	
	}
}

void avr_cpp_lib::pwm_worker::cycle(uint8_t i) {
	if (i == 0) {
		turn_all_on();
	} else if (i < PWM_MAX) {
		for (pwm_channel * x = data; x->channel != PWM_CHANNEL_END_VALUE; x++) {
			if (x->value == i) {
				CLEARBIT(*(x->port), x->channel);
			}
		}
	}
}

void avr_cpp_lib::pwm_worker::turn_all_on() {
	for (pwm_channel * x = data; x->channel != PWM_CHANNEL_END_VALUE; x++) {
		if (x->value != 0) {
			SETBIT(*(x->port), x->channel);
		} else {
			CLEARBIT(*(x->port), x->channel);
		}
	}
}
