#include <fstream>
#include <filesystem>
#include <iostream>
#include <map>
#include <openssl/md5.h>
#include <vector>


std::string get_fingerprint(std::filesystem::path path) {
    return "Hello World";
}

int main(int argc, char *argv[] ) {

    /*std::cout << "Photonic version 1.0" << std::endl;

    if (argc != 2) {
        std::cerr << "Please provide exactly one parameter" << std::endl;
        return 1;
    }

    std::string target_directory = argv[1];

    if (!std::filesystem::is_directory(argv[1])) {
        std::cerr << "Path '" << target_directory << "' does not exist or is not a directory" << std::endl;
        return 1;
    }*/

    std::map<std::string, std::string> fingerprints;
    if (fingerprints.find("a") != fingerprints.end()) {
        
    }
    fingerprints.insert(std::make_pair("a","a"));
    fingerprints.insert(std::make_pair("a","a"));

    /*for (const auto& p: std::filesystem::recursive_directory_iterator(std::filesystem::path(target_directory))) {
        if (!std::filesystem::is_directory(p)) {

            std::cout << p.path() << std::endl;
        }
    }*/

    // Calculate sha256 for each file in the target folder
        // try to add the file to a hash table. The sha256 is the key
        // if add fails, add the file to an array of file that will be deleted

        // show green '+' sign if file is added to


    // delete all files that are listed in the array of deletion candidates

    // rename all remaining files to sha256.ext


  return 0;
}
