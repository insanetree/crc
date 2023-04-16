#include "BitBuffer.hpp"

BitBuffer::BitBuffer(std::istream& in) : input(in) {
	cnt = buffer_size;
}

int BitBuffer::get_bit() {
	if(input.eof() && cnt >= buffer_size) {
		return -1;
	}
	if(cnt >= buffer_size) {
		cnt = 0;
		input.read(&buffer, 1);
	}
	cnt++;
	int ret = buffer>>(buffer_size - 1) & 0x1;
	buffer <<= 1;
	return ret;
}
