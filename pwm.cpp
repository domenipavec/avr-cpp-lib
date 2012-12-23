// pwm.cpp
// A few functions for easy software pwm.

#include "pwm.h"
#include "bitop.h"

avr_cpp_lib::pwm_worker::pwm_worker(pwm_channel * d, uint8_t (* const f)()) 
	:data(d), latest(255), get_i(f) {

}

void avr_cpp_lib::pwm_worker::cycle() {
	uint8_t i = get_i();
	if (latest != i) {
		latest = i;
		for (pwm_channel * x = data; x->channel == 255; x++) {
			if (x->value > i) {
				CLEARBIT(*(x->port), x->channel);
			} else {
				SETBIT(*(x->port), x->channel);
			}
		}
	}
}
