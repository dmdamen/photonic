#include <fstream>
#include <filesystem>
#include <iostream>
#include <openssl/md5.h>
#include <vector>

int main(int argc, char *argv[] ) {

    std::cout << "Photonic version 1.0" << std::endl;
    
    std::cout << argc << std::endl;

    for (int i=0; i<argc; i++) {
        std::cout << (std::string) argv[i] <<std::endl;
    }

    // Parse & test commandline parameters

    // Calculate sha256 for each file in the target folder
        // try to add the file to a hash table. The sha256 is the key
        // if add fails, add the file to an array of file that will be deleted
        
        // show green '+' sign if file is added to


    // delete all files that are listed in the array of deletion candidates

    // rename all remaining files to sha256.ext


  return 0;
}
