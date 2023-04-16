#include "BitBuffer.hpp"

BitBuffer::BitBuffer(std::istream& in) : input(in), bytes_read(0) {
	cnt = buffer_size;
	input.seekg(0, std::ios::end);
	stream_size = input.tellg();
	input.seekg(0);
}

int BitBuffer::get_bit() {
	if(bytes_read >= stream_size && cnt >= buffer_size) {
		return -1;
	}
	if(cnt >= buffer_size) {
		cnt = 0;
		input.read(&buffer, 1);
		bytes_read++;
	}
	cnt++;
	int ret = buffer>>(buffer_size - 1) & 0x1;
	buffer <<= 1;
	return ret;
}
