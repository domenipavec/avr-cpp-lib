/* File: pid.h
 * Pid contains a class for easy PID control. Based on AVR221.
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
#ifndef PID_H
#define PID_H

#define __STDC_LIMIT_MACROS
#include <stdint.h>

namespace avr_cpp_lib {
	struct PidData {
		int16_t processValue;
		int16_t setPoint;
	};

	class Pid {
	public:
		Pid(int16_t p, int16_t i, int16_t d, int16_t min, int16_t max);
		int16_t controller(PidData pd);
		inline void resetIntegrator() {
			this->sumError = 0;
		}

	private:
		int16_t lastProcessValue;
		int32_t sumError;
		const int16_t P_Factor;
		const int16_t I_Factor;
		const int16_t D_Factor;
		const int16_t maxError;
		const int16_t maxRet;
		const int16_t minRet;
		const int32_t maxSumError;

		static const int16_t SCALING_FACTOR = 7;
		static const int16_t MAX_INT = INT16_MAX;
		static const int32_t MAX_LONG = INT32_MAX;
		static const int32_t MAX_I_TERM = (MAX_LONG / 2);
	};
}

#endif
