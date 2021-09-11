#include "blockreader.hpp"
#include <algorithm>

Blockreader::Blockreader(const std::string filepath) : 
	Blockreader(filepath, 32786) { }

Blockreader::Blockreader(const std::string filepath, const size_t blocksize) : 
	file_path {filepath}, max_block_size {blocksize} {
		stream >> std::noskipws;
	 }

Blockreader::~Blockreader() {
	this->stream.close();
}

/*
void Blockreader::Open() {
	this->stream.open(filepath,std::ios::in | 
							   std::ifstream::ate | 
							   std::ifstream::binary);
	filesize = stream.tellg();
	stream.seekg(0);
}

void Blockreader::Close() {
	this->stream.close();
}


std::vector<uint8_t> *Blockreader::ReadBlock() {
	
	std::vector<uint8_t> *block = new std::vector<uint8_t>();

	if (stream.tellg() >= filesize) {
		return block;
	}

	size_t size {blocksize};
	if (filesize - stream.tellg() < blocksize ) {
		size = filesize - stream.tellg();
	}

	std::copy_n(std::istream_iterator<uint8_t>(stream),size, std::back_inserter(*block));
	return block;
}

size_t Blockreader::GetBlockSize() {

	
	return blocksize;
}
*/