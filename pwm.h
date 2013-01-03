/* File: pwm.h
 * This file is part of the avr-cpp-lib, a library containing a few C++ classes,
 * to make your avr programming easier.
 * PWM contains a pwm_worker class definition for easy software pwm.
 */
/* This work is licensed under the 
 * Creative Commons Attribution-ShareAlike 3.0 Unported License. 
 * To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by-sa/3.0/ 
 * or send a letter to 
 * Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
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
