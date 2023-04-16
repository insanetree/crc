#ifndef BITBUFFER_HPP
#define BITBUFFER_HPP

#include <istream>

class BitBuffer {
public:
	BitBuffer(std::istream&);
	virtual int get_bit();
protected:
	static const char buffer_size = sizeof(char)*8;
	std::istream& input;
	char buffer;
	char cnt;
	long stream_size;
	long bytes_read;
};

#endif
