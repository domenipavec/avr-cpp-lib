/* File: cc1101.h
 * Interface to transceiver cc1101. All comunication is synchronous.
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
#ifndef CC1101_H
#define CC1101_H

#include <stdint.h>

#include "io.h"

namespace avr_cpp_lib {

	typedef uint8_t (*transceive_t)(const uint8_t &);

	class CC1101 {
	public:
		CC1101(transceive_t t, OutputPin csn, InputPin so);
		void reset();
		inline void command(uint8_t & address) { transceive(address); }
	private:
		transceive_t transceive;
		OutputPin CSn;
		InputPin SO;

		// constants
		const uint8_t READ = 0x80;
		const uint8_t BURST = 0x40;
		const uint8_t SRES = 0x30;
	};

}

#endif
