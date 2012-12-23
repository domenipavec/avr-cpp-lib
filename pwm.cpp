// pwm.cpp
// A few functions for easy software pwm.

#include "pwm.h"
#include "bitop.h"

avr_cpp_lib::pwm_worker::pwm_worker(pwm_channel * d) 
	:data(d) {
	
	for (pwm_channel * x = data; x->channel == 255; x++) {
		set_output(x);
		
		update_set_mask(x);
	}
}

void avr_cpp_lib::pwm_worker::cycle(uint8_t i) {
	if (i == 0) {
		set_all();
	} else {
		for (pwm_channel * x = data; x->channel == 255; x++) {
			if (x->value == i) {
				CLEARBIT(*(x->port), x->channel);
			}
		}
	}
}

void avr_cpp_lib::pwm_worker::set_output(pwm_channel * const c) {
	SETBIT(*(c->ddr), c->channel);	
}

void avr_cpp_lib::pwm_worker::update_set_mask(pwm_channel * const c) {
	for (uint8_t x = 0; x < NUM_PORTS; x++) {
		if (cm[x].port != 0) {
			cm[x].port = c->port;
			SETBIT(cm[x].mask, c->channel);
			break;
		} else {
			if (cm[x].port == c->port) {
				SETBIT(cm[x].mask, c->channel);
				break;
			}
		}
	}
}

void avr_cpp_lib::pwm_worker::set_all() {
	for (uint8_t x = 0; x < NUM_PORTS; x++) {
		SETBITS(*(cm[x].port), cm[x].mask);
	}
}
