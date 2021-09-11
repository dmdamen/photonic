add_library(graph SHARED
            include/graph.hpp
            graph.cpp
            )

target_include_directories(graph
          PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
          )
