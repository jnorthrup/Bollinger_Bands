cmake_minimum_required(VERSION 3.8)
project(Bollinger_Bands)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        Data.cpp
        Performance.cpp
        Strategy.cpp
        main.cpp
        )

add_executable(Bollinger_Bands ${SOURCE_FILES})