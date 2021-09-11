#ifndef __photonic_hash_hpp
#define __photonic_hash_hpp

#include <fstream>
#include <openssl/sha.h>
#include <string.h>

class Hash {

private:
	SHA256_CTX *_sha256state;
	std::string _value {};

public:
	Hash();							// No-args constructor
	Hash(const Hash &);				// Copy constructor
	Hash(Hash &&);					// Move constructor
	~Hash();						// Destructor

	Hash &operator=(const Hash &);	// Copy assignment
	Hash &operator=(Hash &&);		// Move assignment

	std::string Get() const;		
	void StartHash();
	void UpdateHash(char);
	void UpdateHash(char *, int);
	void FinalizeHash();
	
};

#endif // __photonic_hash_hpp
