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

	typedef uint8_t (*transceive_t)(const uint8_t);

	class CC1101 {
	public:
		CC1101(transceive_t t, OutputPin csn, InputPin so);
		void reset();
		void command(const uint8_t address);
		void write(const uint8_t address, const uint8_t data);
		void writeBurst(const uint8_t address, const uint8_t * data, uint8_t n);
		uint8_t read(const uint8_t address);
		void readBurst(const uint8_t address, uint8_t * data, uint8_t n);
		
	private:
		transceive_t transceive;
		OutputPin CSn;
		InputPin SO;

		// constants
		static const uint8_t READ = 0x80;
		static const uint8_t BURST = 0x40;
	public:
		// commands
		static const uint8_t SRES = 0x30;
		static const uint8_t SFSTXON = 0x31;
		static const uint8_t SXOFF = 0x32;
		static const uint8_t SCAL = 0x33;
		static const uint8_t SRX = 0x34;
		static const uint8_t STX = 0x35;
		static const uint8_t SIDLE = 0x36;
		static const uint8_t SWOR = 0x38;
		static const uint8_t SPWD = 0x39;
		static const uint8_t SFRX = 0x3A;
		static const uint8_t SFTX = 0x3B;
		static const uint8_t SWORRST = 0x3C;
		static const uint8_t SNOP = 0x3D;
		
		// addresses
		static const uint8_t IOCFG2 = 0X00;
		static const uint8_t IOCFG1 = 0X01;
		static const uint8_t IOCFG0 = 0X02;
		static const uint8_t FIFOTHR = 0X03;
		static const uint8_t SYNC1 = 0X04;
		static const uint8_t SYNC0 = 0X05;
		static const uint8_t PKTLEN = 0X06;
		static const uint8_t PKTCTRL1 = 0X07;
		static const uint8_t PKTCTRL0 = 0X08;
		static const uint8_t ADDR = 0X09;
		static const uint8_t CHANNR = 0X0A;
		static const uint8_t FSCTRL1 = 0X0B;
		static const uint8_t FSCTRL0 = 0X0C;
		static const uint8_t FREQ2 = 0X0D;
		static const uint8_t FREQ1 = 0X0E;
		static const uint8_t FREQ0 = 0X0F;
		static const uint8_t MDMCFG4 = 0X10;
		static const uint8_t MDMCFG3 = 0X11;
		static const uint8_t MDMCFG2 = 0X12;
		static const uint8_t MDMCFG1 = 0X13;
		static const uint8_t MDMCFG0 = 0X14;
		static const uint8_t DEVIATN = 0X15;
		static const uint8_t MCSM2 = 0X16;
		static const uint8_t MCSM1 = 0X17;
		static const uint8_t MCSM0 = 0X18;
		static const uint8_t FOCCFG = 0X19;
		static const uint8_t BSCFG = 0X1A;
		static const uint8_t AGCTRL2 = 0X1B;
		static const uint8_t AGCTRL1 = 0X1C;
		static const uint8_t AGCTRL0 = 0X1D;
		static const uint8_t WOREVT1 = 0X1E;
		static const uint8_t WOREVT0 = 0X1F;
		static const uint8_t WORCTRL = 0X20;
		static const uint8_t FREND1 = 0X21;
		static const uint8_t FREND0 = 0X22;
		static const uint8_t FSCAL3 = 0X23;
		static const uint8_t FSCAL2 = 0X24;
		static const uint8_t FSCAL1 = 0X25;
		static const uint8_t FSCAL0 = 0X26;
		static const uint8_t RCCTRL1 = 0X27;
		static const uint8_t RCCTRL0 = 0X28;
		static const uint8_t FSTEST = 0X29;
		static const uint8_t PTEST = 0X2A;
		static const uint8_t AGCTEST = 0X2B;
		static const uint8_t TEST2 = 0X2C;
		static const uint8_t TEST1 = 0X2D;
		static const uint8_t TEST0 = 0X2E;
		static const uint8_t PATABLE = 0X3E;
		static const uint8_t FIFO = 0X3F;
		// these are only readable with burst mode
		static const uint8_t PARTNUM = 0X30;
		static const uint8_t VERSION = 0X31;
		static const uint8_t FREQEST = 0X32;
		static const uint8_t LQI = 0X33;
		static const uint8_t RSSI = 0X34;
		static const uint8_t MARCSTATE = 0X35;
		static const uint8_t WORTIME1 = 0X36;
		static const uint8_t WORTIME0 = 0X37;
		static const uint8_t PKTSTATUS = 0X38;
		static const uint8_t VCO_VC_DAC = 0X39;
		static const uint8_t TXBYTES = 0X3A;
		static const uint8_t RXBYTES = 0X3B;
		static const uint8_t RCCTRL1_STATUS = 0X3C;
		static const uint8_t RCCTRL0_STATUS = 0X3D;
	};

}

#endif
