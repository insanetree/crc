#include "Crc.hpp"

Crc::Crc(unsigned long long p):polynomial((p<<2)+1), msb(0) {
	while(1<<msb <= p)
		msb++;
}

unsigned char Crc::get_msb() const {
	return msb;
}

unsigned long long calculate_checksum(std::istream& input) {
	input.seekg(0);
	return 0;
}
