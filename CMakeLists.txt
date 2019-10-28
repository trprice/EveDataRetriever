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

# No Boost Cmake is a fallback. Use Mutlithreaded *should* be the thing to use but it doesn't work for now.
# 		See: https://gitlab.kitware.com/cmake/cmake/issues/19714
#set( Boost_USE_MULTITHREADED ON )
set(Boost_NO_BOOST_CMAKE 1)
find_package(Boost COMPONENTS chrono thread REQUIRED)
             
# Use C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add source to this project's executable.
add_executable (EveDataRetriever "EveDataRetriever.cpp" "EveDataRetriever.h")

target_link_libraries(EveDataRetriever PRIVATE cpprestsdk::cpprest cpprestsdk::cpprestsdk_zlib_internal cpprestsdk::cpprestsdk_boost_internal Boost::thread Boost::chrono) 
