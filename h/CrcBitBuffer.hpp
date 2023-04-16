#ifndef CRCBITBUFFER_HPP
#define CRCBITBUFFER_HPP

#include "BitBuffer.hpp"
#include "Crc.hpp"

class CrcBitBuffer : public BitBuffer {
public:
	CrcBitBuffer(std::istream&, Crc&);
	virtual int get_bit() override;
private:
	char msb;
};

#endif
