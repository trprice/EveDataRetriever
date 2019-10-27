# CMakeList.txt : CMake project for EveDataRetriever, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project(EveDataRetriever)

#if (NOT CPPRESTSDK_PATH)
#  set(CPPRESTSDK_PATH  "")
#endif()

find_package(cpprestsdk
             CONFIG
             REQUIRED)
             
# Use C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add source to this project's executable.
add_executable (EveDataRetriever "EveDataRetriever.cpp" "EveDataRetriever.h")

target_link_libraries(EveDataRetriever PRIVATE cpprestsdk::cpprest cpprestsdk::cpprestsdk_zlib_internal cpprestsdk::cpprestsdk_boost_internal) #cpprestsdk::cpprestsdk_brotli_internal)
