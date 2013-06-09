/* File: pid.cpp
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

#include "pid.h"

avr_cpp_lib::Pid::Pid(int16_t p, int16_t i, int16_t d, int16_t min, int16_t max)
	: sumError(0), lastProcessValue(0),
	  P_Factor(p), I_Factor(i), D_Factor(d),
	  maxError(MAX_INT / (p + 1)), maxSumError(MAX_I_TERM / (i + 1)),
	  minRet(min), maxRet(max) {
	
}

int16_t avr_cpp_lib::Pid::controller(PidData pd) {
	int16_t error, p_term;
	int32_t i_term, ret, temp;

	error = pd.setPoint - pd.processValue;
	
	// Calculate Pterm and limit error overflow
	if (error > this->maxError) {
		p_term = MAX_INT;
	} else if (error < -this->maxError) {
		p_term = -MAX_INT;
	} else {
		p_term = this->P_Factor * error;
	}

	// Calculate Iterm and limit integral runaway
	temp = this->sumError + error;
	if (temp > this->maxSumError) {
		i_term = MAX_I_TERM;
		this->sumError = this->maxSumError;
	} else if (temp < -this->maxSumError) {
		i_term = -MAX_I_TERM;
		this->sumError = -this->maxSumError;
	} else {
		this->sumError = temp;
		i_term = this->I_Factor * this->sumError;
	}
	
	// Calculate d-term and combine
	ret = (p_term + i_term + this->D_Factor * (this->lastProcessValue - pd.processValue)) >> SCALING_FACTOR;

	this->lastProcessValue = pd.processValue;
	if (ret > this->maxRet) {
		return this->maxRet;
	}
	if (ret < this->minRet) {
		return this->minRet;
	}

	return ((int16_t)ret);
}
