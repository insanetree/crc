#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <unordered_set>
#include <exception>

static const int param_num = 4;
static const int err_param = 1;
static const int err_poly = 2;
static const int err_file = 3;
static const int err_action = 4;

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
	return 0;
}
