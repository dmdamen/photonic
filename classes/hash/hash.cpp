#include <cstring>
#include <iomanip>
#include <iostream>
#include <string.h>

#include "hash.hpp"

Hash::Hash() {
	_sha256state = (SHA256_CTX *) malloc(sizeof(SHA256_CTX));
}

Hash::Hash(const Hash &source) 
	: _value{source._value} {
	
	_sha256state = (SHA256_CTX *) malloc(sizeof(SHA256_CTX));
	std::memcpy(_sha256state, source._sha256state, sizeof(SHA256_CTX));
}

Hash::Hash(Hash &&source) 
	: _value{source._value},
	  _sha256state {source._sha256state} {
		  source._sha256state = nullptr;
}

Hash &Hash::operator=(const Hash &source) {
	if (this == &source) {
		return *this;
	}

	this->_value = source._value;
	std::memcpy(this->_sha256state, source._sha256state, sizeof(SHA256_CTX));

	return *this;
}

Hash &Hash::operator=(Hash &&source) {
	if (this == &source) {
		return *this;
	}

	this->_value = source._value;

	delete [] _sha256state;
	_sha256state = source._sha256state;
	source._sha256state = nullptr;

	return *this;
}

void Hash::StartHash() {
	SHA256_Init(_sha256state);
	_value.clear();
}

void Hash::UpdateHash(char c) {
	SHA256_Update(_sha256state, &c, 1);
}

void Hash::UpdateHash(char *buffer, int length) {
	SHA256_Update(_sha256state, buffer, length);
}

void Hash::FinalizeHash() {
	unsigned char *md = (unsigned char *) malloc(SHA256_DIGEST_LENGTH);
	SHA256_Final(md,_sha256state);
	
	std::stringstream returnStream;

	for (int i=0; i < SHA256_DIGEST_LENGTH; i++) {
		returnStream << std::setfill('0') 
                     << std::setw(2)
                     << std::hex
                     << (0xff & (md[i]));
	}

	_value = returnStream.str();
}

std::string Hash::Get() const {
	return _value;
}

Hash::~Hash() {
	delete [] _sha256state;
} 