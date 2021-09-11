#include <algorithm>
#include <cstring>

#include "filereader.hpp"

Filereader::Filereader(const std::string path) : 
	Filereader(path, 65536) { }

Filereader::Filereader(const std::string path, const size_t maxBufferLength) : 
	m_path {path}, m_maxChunksize {maxBufferLength} {
		m_stream >> std::noskipws;
        m_stream.open(m_path, std::ios::binary | std::ios::in | std::ios::ate);
        if (!m_stream.is_open()) {
            throw std::runtime_error(std::string("Could not open file for reading") + m_path);
        }

        m_chunk = (char *) malloc(m_maxChunksize * sizeof(char));
        m_numChunks = m_stream.tellg() / m_maxChunksize + 1;
        m_stream.seekg(0);

        // read the first block into 
        // buffer for immediate use
        m_readNextChunk();
	 }

Filereader::~Filereader() {
    if (!m_stream.is_open()) {
        m_stream.close();
    }
    delete [] m_chunk;
}

const char *Filereader::CurrentChunk() const {
    return  m_chunk;
}

const size_t Filereader::SizeOfCurrentChunk() const {
    return m_chunksize;
}

const size_t Filereader::TotalNumberOfchunks() const {
    return m_numChunks;
}

void Filereader::m_readNextChunk() {
    m_chunksize = m_stream.readsome(m_chunk, m_maxChunksize);
}