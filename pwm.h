// pwm.h
// A few functions for easy software pwm.
// 0 is always on

#ifndef PWM_H
#define PWM_H

#include <stdint.h>

#define NUM_PORTS 4

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
			void set_output(pwm_channel * const);
			void set_all();
			
			pwm_channel * const data;
	};
}

#endif
