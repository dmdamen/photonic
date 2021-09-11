#ifndef __photonic_filereader
#define __photonic_filereader

#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>

class Filereader {

private:
    char  *m_chunk             {};
    size_t m_chunksize         {0};
    size_t m_numChunks         {0};
    size_t m_maxChunksize      {0};
    size_t m_chunkIndex        {0};
    std::string m_path         {};
    std::ifstream m_stream     {};
    
    void m_readNextChunk();


public:
    Filereader() = delete;
    Filereader(const std::string);
    Filereader(const std::string, const size_t);
    Filereader(const Filereader &) = delete;	        // Copy constructor
	Filereader(Filereader &&) = delete;					// Move constructor
    ~Filereader();                                      // Destructor should delete the buffer

    Filereader &operator=(const Filereader &) = delete;	// Copy assignment
	Filereader &operator=(Filereader &&) = delete;		// Move assignment

    const size_t TotalNumberOfchunks() const;
    const size_t SizeOfCurrentChunk() const;
    const char * CurrentChunk() const;                  // make sure you cannot accidentally change  
                                                        // the buffer contents from outside this 
                                                        // class. Do something with const here

};

#endif // __photonic_filereader