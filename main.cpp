#include <fstream>
#include <filesystem>
#include <iostream>
#include <openssl/md5.h>
#include <vector>

#include "photonic.hpp"

struct mediafile {
    std::string fingerprint;
    std::string source;
    std::string extension;
    std::vector<std::string> destinations;
};

std::string getFileExt(const std::string& s) {

   size_t i = s.rfind('.', s.length());
   if (i != std::string::npos) {
      return(s.substr(i+1, s.length() - i));
   }

   return("");
}

int main(int argc, char *argv[] ) {

    std::cout << "Photonic version " << PHOTONIC_VERSION_MAJOR << "." << PHOTONIC_VERSION_MINOR << std::endl;
    
    // Parse & test commandline parameters

    // Calculate sha256 for each file in the target folder
        // try to add the file to a hash table. The sha256 is the key
        // if add fails, add the file to an array of file that will be deleted
        
        // show green '+' sign if file is added to


    // delete all files that are listed in the array of deletion candidates

    // rename all remaining files to sha256.ext

    

    return 0; 
    //loading configuration

    size_t numFiles {0};


  return 0;
}
