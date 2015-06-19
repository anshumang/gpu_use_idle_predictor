cmake_minimum_required(VERSION 2.8)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE "Debug")

SET_PROPERTY(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS TRUE)

add_library(cupti SHARED IMPORTED)
set_property(TARGET cupti PROPERTY IMPORTED_LOCATION "/usr/local/cuda/extras/CUPTI/lib64/libcupti.so")

project(gpu_use_idle_predictor)

include_directories(include ../include /usr/include /usr/local/cuda/extras/CUPTI/include /usr/include /usr/local/cuda/include)

add_library(gpu_use_idle_predictor SHARED src/external.cpp src/CuptiProfiler.cpp)

target_link_libraries(gpu_use_idle_predictor cupti)
