add_library(blockreader SHARED
            include/blockreader.hpp
            blockreader.cpp
            )

target_include_directories(blockreader
          PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
          )