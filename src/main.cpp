#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <unordered_set>
#include <exception>

#include "Crc.hpp"

static const int param_num = 4;
static const int err_param = 1;
static const int err_poly = 2;
static const int err_file = 3;
static const int err_action = 4;

void encode(std::istream& in, std::ostream& out, Crc& crc);

int main(int argc, char* argv[]) {
	//all the input argument checks
	if(argc != param_num) {
		std::cerr<<"Incorrect number of arguments"<<std::endl\
			<<"Usage:"<<std::endl\
			<<"./crc action polynomial file"<<std::endl;
		std::exit(err_param);
	}
	std::string action = std::string(argv[1]);
	if(!(action == "d" || action == "c")) { 
		std::cerr<<"Invalid action. Valid actions are 'c' and 'd'"\
			<<std::endl;
		std::exit(err_action);
	}
	unsigned long long polynomial;
	std::string filename = std::string(argv[3]);
	try {
		polynomial = std::stoull(argv[2], nullptr, 16);
	} catch(std::logic_error&) {
		std::cerr<<"Invalid polynomial"<<std::endl;
		std::exit(err_poly);
	}
	std::ifstream input(filename, std::ios::in|std::ios::binary);
	if(!input.is_open()) {
		std::cerr<<filename<<" does not exist"<<std::endl;
		std::exit(err_file);
	}
	Crc crc(polynomial);
	if(action == "c") {
		std::string outname = filename + ".crc";
		std::ofstream output(outname, std::ios::out|std::ios::binary);
		encode(input, output, crc);
		output.close();
	} else if(action == "d") {
		std::cout<<crc.calculate_checksum(input);
	}
	input.close();
	return 0;
}

void encode(std::istream& in, std::ostream& out, Crc& crc) {
	char byte;
	unsigned long long checksum;
	in.seekg(0, std::ios::end);
	long size = in.tellg();
	in.seekg(0);
	char *buffer = new char[size];
	in.read(buffer,size);
	out.write(buffer,size);
	delete[] buffer;
	out.flush();
	in.clear();
	in.seekg(0, std::ios::beg);
	checksum = crc.calculate_checksum(in);
	checksum <<= (8*sizeof(checksum) - crc.get_msb());
	for(int i = 0 ; i < crc.get_msb() ; i += 8) {
		byte = checksum >> 56;
		checksum <<= 8;
		out.write(&byte, 1);
	}
	out.flush();
}
