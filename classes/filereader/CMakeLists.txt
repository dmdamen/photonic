add_library(filereader SHARED
            include/filereader.hpp
            filereader.cpp
            )

target_include_directories(filereader
          PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
          )
