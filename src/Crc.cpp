#include "Crc.hpp"
#include "BitBuffer.hpp"

Crc::Crc(unsigned long long p):polynomial((p<<1)+1), msb(0) {
	while(1<<msb <= p)
		msb++;
}

unsigned char Crc::get_msb() const {
	return msb;
}

unsigned long long Crc::calculate_checksum(std::istream& input) {
	input.seekg(0);
	BitBuffer buffer(input);
	unsigned long long remainder = 0;
	int bit;
	while((bit = buffer.get_bit()) >= 0) {
		remainder <<= 1;
		remainder |= bit;
		if(remainder >= (1<<msb)) {
			remainder ^= polynomial;
		}
	}
	return remainder;
}
