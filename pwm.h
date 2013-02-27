/* File: pwm.h
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
#ifndef PWM_H
#define PWM_H

// a final entry channel value
#define PWM_CHANNEL_END_VALUE 255

// a final entry for pwm_worker data, that signifies the end of array
#define PWM_CHANNEL_END {0, 0, PWM_CHANNEL_END_VALUE, 0}

// max PWM value, at which leds are constantly on
#define PWM_MAX 255

#include <stdint.h>

namespace avr_cpp_lib {

	struct pwm_channel {
		uint8_t volatile * const ddr;
		uint8_t volatile * const port;
		uint8_t const channel;
		uint8_t volatile value;
	};
	
	class pwm_worker {
	
		public:
			pwm_worker(pwm_channel *);
			void cycle(uint8_t);
			
		private:
			void turn_all_on();
			
			pwm_channel * const data;
	};
}

#endif
