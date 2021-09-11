#ifndef __photonic_blockreader_hpp

#define __photonic_blockreader_hpp

#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>

class Blockreader {

private:
	size_t max_block_size {0};						// need to know large the block need to be
	size_t file_size {0};							// size of the file
	size_t current_block_size {0};					// size of the block that is currently read into memory
	uint8_t *current_block {nullptr};				// data block that is currently available in memory
	std::ifstream stream {};			    		// stream we are reading from
	std::string file_path {};						// full path to the file

public:
	Blockreader() = delete;							// delete default no-args constuctor
	Blockreader(const std::string);					// constructor that accepts a filestream
	Blockreader(const std::string, const size_t);	// constructor that accepts a filestream and a blocksize
	~Blockreader();									// Don't forget to close the stream

	size_t Next();									// Read next block of data into memory and return the result
	size_t Previous();
	size_t First();
	size_t Last();


	//size_t GetBlock(char *buffer);				// Read the next block from the file. Returns the true  of the block.
	//void Open();
	//void Close();
	//size_t GetBlockSize();

};

#endif // __photonic_blockreader_hpp
