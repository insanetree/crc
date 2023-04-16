#include "CrcBitBuffer.hpp"

CrcBitBuffer::CrcBitBuffer(std::istream& in, Crc& crc) : BitBuffer(in) {
	msb = crc.get_msb();
}

int CrcBitBuffer::get_bit() {
	int ret = BitBuffer::get_bit();
	if(ret >= 0)
		return ret;
	msb--;
	if(msb >= 0)
		return 0;
	return -1;
}
