#include <fstream>
#include <filesystem>
#include <iostream>
#include <map>
#include <openssl/sha.h>
#include <vector>


std::string get_fingerprint(std::filesystem::path path) {

    // Get file length
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    // Initialize hash algoritm
    SHA256_CTX *_sha256state = (SHA256_CTX *) malloc(sizeof(SHA256_CTX));
    SHA256_Init(_sha256state);

    // Read file into hashing algorithm
    std::vector<char> buffer(size);
    if (file.read(buffer.data(), size)) {
        SHA256_Update(_sha256state, buffer.data(), size);
    } else {
        throw std::runtime_error(std::string("Could not open file for reading" + (std::string) path));
    }  

    file.close();

    // Finalize hash
    unsigned char *md = (unsigned char *) malloc(SHA256_DIGEST_LENGTH);
    SHA256_Final(md,_sha256state);

    // Format return string
    std::stringstream returnStream;

    for (int i=0; i < SHA256_DIGEST_LENGTH; i++) {
		returnStream << std::setfill('0') 
                     << std::setw(2)
                     << std::hex
                     << (0xff & (md[i]));
	}

	return returnStream.str();
}

int main(int argc, char *argv[] ) {

    std::cout << "Photonic version 1.0" << std::endl;

    if (argc != 2) {
        std::cerr << "Please provide exactly one parameter" << std::endl;
        return 1;
    }

    std::string target_directory = argv[1];

    if (!std::filesystem::is_directory(target_directory)) {
        std::cerr << "Path '" << target_directory << "' does not exist or is not a directory" << std::endl;
        return 1;
    }

    std::map<std::string, std::filesystem::directory_entry> keepers {};
    std::vector<std::filesystem::directory_entry> fileToBeDeleted {};
    for (const auto& p: std::filesystem::recursive_directory_iterator(std::filesystem::path(target_directory))) {
        if (!std::filesystem::is_directory(p)) {
            std::string fp = get_fingerprint(p.path());
            if (keepers.find(fp) == keepers.end()) {
                std::cout << "\u001b[32m+\u001b[0m " << fp << " " << p.path() << std::endl;
                keepers.insert(std::make_pair(fp,p));
            } else {
                std::cout << "\u001b[31m-\u001b[0m " << fp << " " << p.path() << std::endl;
                fileToBeDeleted.push_back(p);
            }            
        }
    }
  
    // Calculate sha256 for each file in the target folder
        // try to add the file to a hash table. The sha256 is the key
        // if add fails, add the file to an array of file that will be deleted

        // show green '+' sign if file is added to


    // delete all files that are listed in the array of deletion candidates

    // rename all remaining files to sha256.ext


  return 0;
}
