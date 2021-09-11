add_library(hash SHARED
            include/hash.hpp
            hash.cpp
            )

target_include_directories(hash
          PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
          )

#find_package(OpenSSL REQUIRED)

#target_link_libraries(hash PUBLIC OpenSSL::SSL)
