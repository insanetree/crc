#ifndef BITBUFFER_HPP
#define BITBUFFER_HPP

#include <istream>

class BitBuffer {
public:
	BitBuffer(std::istream&);
	int get_bit();
private:
	static const char buffer_size = sizeof(char)*8;
	std::istream& input;
	char buffer;
	char cnt;
};

#endif
