#ifndef CRC_HPP
#define CRC_HPP

#include <istream>

class Crc {
public:
	/**
	 * parameter is a crc polynomial given in Koopman notation
	 */
	Crc(unsigned long long);
	unsigned char get_msb() const;
	unsigned long long calculate_checksum(std::istream&);
protected:
private:
	unsigned long long polynomial;
	unsigned char msb;
};
#endif
