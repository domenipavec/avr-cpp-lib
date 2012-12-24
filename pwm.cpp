// pwm.cpp
// A few functions for easy software pwm.

#include "pwm.h"
#include "bitop.h"

avr_cpp_lib::pwm_worker::pwm_worker(pwm_channel * d) 
	:data(d) {
	
	for (pwm_channel * x = data; x->channel != 255; x++) {
		set_output(x);
	}
}

void avr_cpp_lib::pwm_worker::cycle(uint8_t i) {
	if (i == 0) {
		set_all();
	} else if (i != 255) {
		for (pwm_channel * x = data; x->channel != 255; x++) {
			if (x->value == i) {
				CLEARBIT(*(x->port), x->channel);
			}
		}
	}
}

void avr_cpp_lib::pwm_worker::set_output(pwm_channel * const c) {
	SETBIT(*(c->ddr), c->channel);	
}

void avr_cpp_lib::pwm_worker::set_all() {
	for (pwm_channel * x = data; x->channel != 255; x++) {
		if (x->value != 0) {
			SETBIT(*(x->port), x->channel);
		}
	}
}
