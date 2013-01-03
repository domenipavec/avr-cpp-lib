/* File: pwm.cpp
 * This file is part of the avr-cpp-lib, a library containing a few C++ classes,
 * to make your avr programming easier.
 * PWM contains a pwm_worker class for easy software pwm.
 */
/* This work is licensed under the 
 * Creative Commons Attribution-ShareAlike 3.0 Unported License. 
 * To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by-sa/3.0/ 
 * or send a letter to 
 * Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
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
		}
	}
}
