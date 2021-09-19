cmake_minimum_required(VERSION 3.16)

# set the project name
project(photonic VERSION 0.0)

# set the c++ standard to c17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Pass the project version to the source code
configure_file(photonic.hpp.in photonic.hpp)

# add the executable
add_executable(photonic main.cpp)

find_package(OpenSSL REQUIRED)

target_link_libraries(photonic PUBLIC OpenSSL::SSL)
#target_link_libraries(photonic PUBLIC hash)

# add the binary tree to the search path for include files
# so that we can find photonic.h file
target_include_directories(photonic PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
