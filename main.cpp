#include "json/json.h"
#include <fstream>
#include <filesystem>
#include <iostream>
#include <openssl/md5.h>
#include <vector>

#include "filereader.hpp"
#include "hash.hpp"
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

int main(void) {

    std::cout << "Photonic version " << PHOTONIC_VERSION_MAJOR << "." << PHOTONIC_VERSION_MINOR << std::endl;

    //loading configuration
    Json::Value root;
    std::ifstream config("config.json", std::ifstream::binary);
    config >> root;
    const Json::Value sources = root["sources"];
    const Json::Value destinations = root["destinations"];

    size_t numFiles {0};
    for ( int index = 0; index < sources.size(); ++index ) {

        for (const auto& p: std::filesystem::recursive_directory_iterator(std::filesystem::path(sources[index].asString()))) {
            if (!std::filesystem::is_directory(p)) {

                struct mediafile _mediafile {};
                _mediafile.source = p.path();
                _mediafile.extension = getFileExt(p.path());

                std::ifstream file(p.path(), std::ios::binary | std::ios::ate);
                std::streamsize size = file.tellg();
                file.seekg(0, std::ios::beg);

                Hash H;
                H.StartHash();

                std::vector<char> buffer(size);
                if (file.read(buffer.data(), size)) {
                    H.UpdateHash(buffer.data(),size);
                } else {
                    throw std::runtime_error(std::string("Could not open file for reading" + (std::string) p.path()));
                }

                H.FinalizeHash();

                file.close();

                _mediafile.fingerprint = H.Get();

                numFiles++;

                bool removeSourceAfterCopy {true};

                for ( int i = 0; i < destinations.size(); i++ ) {
                    std::string destination = destinations[i].asString() 
                                              + "/" 
                                              + _mediafile.fingerprint 
                                              + "." 
                                              + _mediafile.extension;    

                    if (_mediafile.source != destination) {
                        _mediafile.destinations.push_back(destination);
                    } else {
                        removeSourceAfterCopy = false;
                    }                
                }

                for (int i=0; i < _mediafile.destinations.size(); i++) {

                    std::string parent = _mediafile.destinations[i].substr(0, _mediafile.destinations[i].find_last_of("/\\"));
                    std::filesystem::create_directories(parent);

                    std::filesystem::copy_file(
                        std::filesystem::path(_mediafile.source),
                        std::filesystem::path(_mediafile.destinations[i]),
                        std::filesystem::copy_options::skip_existing);
                }

                if (removeSourceAfterCopy == true) {
                    std::filesystem::remove(_mediafile.source);
                }
            }
        }
    }
  
/*
With C++17 the standard way to copy a file will be including the <filesystem> header and using:

bool copy_file( const std::filesystem::path& from,
                const std::filesystem::path& to);

bool copy_file( const std::filesystem::path& from,
                const std::filesystem::path& to,
                std::filesystem::copy_options options);
*/

  return 0;
}
