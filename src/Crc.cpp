#include "Crc.hpp"
#include "CrcBitBuffer.hpp"

Crc::Crc(unsigned long long p):polynomial((p<<1)+1), msb(0) {
	while(1ul<<msb <= p)
		msb++;
}

unsigned char Crc::get_msb() const {
	return msb;
}

unsigned long long Crc::calculate_checksum(std::istream& input) {
	BitBuffer* buffer = new CrcBitBuffer(input, *this);
	unsigned long long remainder = 0;
	int bit;
	while((bit = buffer->get_bit()) >= 0) {
		remainder <<= 1;
		remainder |= bit;
		if(remainder >= (1<<msb)) {
			remainder ^= polynomial;
		}
	}
	delete buffer;
	return remainder;
}
